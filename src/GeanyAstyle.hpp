/*
 * GeanyAstyle.hpp - Arctic Style plugin for the Geany IDE
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

#ifndef __GEANYASTYLE_HPP__
#define __GEANYASTYLE_HPP__

#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus

//#include <geany/geanyplugin.h>
#include <geany/geany.h>
#include <geany/plugindata.h>

#include <geany/document.h>
#include <geany/editor.h>
#include <geany/encodings.h>
#include <geany/filetypes.h>
#include <geany/highlighting.h>
#include <geany/keybindings.h>
#include <geany/msgwindow.h>
#include <geany/prefs.h>
#include <geany/project.h>
#include <geany/search.h>
#include <geany/stash.h>
#include <geany/support.h>
//#include <geany/templates.h>
#include <geany/toolbar.h>
#include <geany/ui_utils.h>
#include <geany/utils.h>

#include <geany/geanyfunctions.h>

// geny variables
GeanyPlugin*    geany_plugin;
GeanyData*      geany_data;
GeanyFunctions* geany_functions;

// geany plugin api functions
gint plugin_version_check(gint version);
void plugin_set_info(PluginInfo* info);
void plugin_init(GeanyData* data);
void plugin_cleanup(void);
GtkWidget* plugin_configure(GtkDialog *dialog);

#ifdef __cplusplus
}
#endif // _cplusplus

#endif // __GEANYASTYLE_HPP__
