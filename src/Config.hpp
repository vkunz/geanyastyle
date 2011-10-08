/*
 * Config.hpp - Arctic Style plugin for the Geany IDE
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

#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <iostream>

namespace libconfig
{
    class Config;
}

class AstyleConfig;

class Config
{
public:
    // ctor
    Config(std::string& configdir);

    // dtor
    virtual ~Config();

    // serialize astyle configuration
    std::string getAstyleConfig() const;

    // read config file and adjust internal state
    void loadSettings();

    // write current state to config file
    void saveSettings();

private:
    // astyle config
    AstyleConfig* m_aconfig;

    // libconfig object
    libconfig::Config* m_lconfig;

    // config file
    std::string m_filePath;

    // create default settings
    void createDefault();
};

#endif // __CONFIG_HPP__
