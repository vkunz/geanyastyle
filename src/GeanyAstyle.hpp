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

#include "GeanyPlugin.hpp"

#if defined(__MINGW32__) || defined(__MINGW64__)
#define STDCALL __stdcall
#else
#define STDCALL
#endif

#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus

// functions required by geany plugin api
gint plugin_version_check(gint version);
void plugin_set_info(PluginInfo* info);
void plugin_init(GeanyData* data);
void plugin_cleanup(void);
GtkWidget* plugin_configure(GtkDialog* dialog);

// signal callbacks
void on_menuitem_activate(GtkMenuItem *menuitem, gpointer user_data);

#ifdef __cplusplus
}
#endif // _cplusplus

class Config;

class GeanyAstyle
{
public:
    // ctor
    GeanyAstyle();

    // dtor
    virtual ~GeanyAstyle();

    void formatDocument();

private:
    static void STDCALL astyleError(int errorCode, const char* errorText);
    static char* STDCALL astyleAlloc(unsigned long size);

    // config
    Config* m_config;
}; // class GeanyAstyle
#endif // __GEANYASTYLE_HPP__
