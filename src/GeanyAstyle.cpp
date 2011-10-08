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

#include "GeanyAstyle.hpp"

// geany variables
GeanyPlugin*    geany_plugin;
GeanyData*      geany_data;
GeanyFunctions* geany_functions;

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
}

void plugin_cleanup(void)
{
}

GtkWidget* plugin_configure(GtkDialog* dialog)
{
    // [TODO] add graphical configuration panel
    GtkWidget* vbox = gtk_vbox_new(FALSE, 1);

    return vbox;
}
