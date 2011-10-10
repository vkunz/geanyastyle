/*
 * GeanyAstyle.cpp - Arctic Style plugin for the Geany IDE
 *
 * Copyright 2011 Valentin Kunz <vale.kunz@googlemail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include <astyle.h>

#include "Config.hpp"
#include "GeanyAstyle.hpp"

// geany variables
GeanyPlugin*    geany_plugin;
GeanyData*      geany_data;
GeanyFunctions* geany_functions;

// geanyastyle plugin object
GeanyAstyle* g_gastyle;

GtkWidget* main_menu_item;

// check API version
gint plugin_version_check(gint abi_ver)
{
    if(abi_ver != GEANY_ABI_VERSION)
    {
        return -1;
    }

    return 201;
}

// populate plugin information
void plugin_set_info(PluginInfo *info)
{
    // [TODO] modify build system: add i18n support
    //main_locale_init((localedir), (package));
    info->name = "GeanyAstyle";
    info->description = "Arctic Style code formatter plugin.";
    info->version = "0.1.0";
    info->author = "Valentin Kunz <vale.kunz@googlemail.com>";
}

void plugin_init(GeanyData* data)
{
    g_gastyle = new GeanyAstyle();

    main_menu_item = gtk_menu_item_new_with_mnemonic("AStyle");

    gtk_container_add(GTK_CONTAINER(geany_data->main_widgets->tools_menu),
                      main_menu_item);
    gtk_widget_show(main_menu_item);

    g_signal_connect(main_menu_item, "activate",
                     G_CALLBACK(on_menuitem_activate), NULL);
}

void plugin_cleanup(void)
{
    gtk_widget_destroy(main_menu_item);

    delete g_gastyle;
}

GtkWidget* plugin_configure(GtkDialog* dialog)
{
    // [TODO] add graphical configuration panel
    GtkWidget* vbox = gtk_vbox_new(FALSE, 1);

    return vbox;
}

void on_menuitem_activate(GtkMenuItem* menuitem, gpointer user_data)
{
    g_gastyle->formatDocument();
}

GeanyAstyle::GeanyAstyle()
{
    std::string configdir(geany_data->app->configdir);
    m_config = new Config(configdir);

    // load settings
    m_config->loadSettings();
}

GeanyAstyle::~GeanyAstyle()
{
    // save settings
    m_config->saveSettings();

    delete m_config;
}

void GeanyAstyle::formatDocument()
{
    GeanyDocument* doc = document_get_current();

    // no opened document
    if(doc == NULL)
    {
        // [TODO] add some error handling here
        return;
    }

    ScintillaObject* sci = doc->editor->sci;

    gint codelength = sci_get_length(sci);

    gchar* ccode = sci_get_contents(sci, codelength + 1);

    std::string code = ccode;

    g_free(ccode);

    std::string aoptions = m_config->getAstyleConfig();

    char* formatted = AStyleMain(code.c_str(), aoptions.c_str(), astyleError, astyleAlloc);

    if(formatted == NULL)
    {
        // [TODO] add some error handling here
        return;
    }

    gint curLine = sci_get_current_line(sci);
    sci_set_text(sci, formatted);

    sci_goto_line(sci, curLine, FALSE);

    delete[] formatted;
}

void GeanyAstyle::astyleError(int errorCode, const char* errorText)
{
    // [TODO] add some error reporting
    std::cout << "errorCode: " << errorCode << std::endl;
    std::cout << "errorText: " << errorText << std::endl;
}

char* GeanyAstyle::astyleAlloc(unsigned long size)
{
    char* buffer = new (std::nothrow) char[size];
    return buffer;
}
