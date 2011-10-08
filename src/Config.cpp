/*
 * Config.cpp - Arctic Style plugin for the Geany IDE
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

#include <boost/filesystem.hpp>

#include <libconfig.h++>

#include "AstyleConfig.hpp"
#include "Config.hpp"

namespace lc = libconfig;

typedef libconfig::Setting lcs;

Config::Config(std::string& configdir)
{
    m_aconfig = new AstyleConfig();

    m_lconfig = new lc::Config();

    boost::filesystem::path p(configdir);

    p /= "plugins";

    if(!is_directory(p))
    {
        boost::filesystem::create_directory(p);
    }

    p /= "geanyastyle";

    if(!is_directory(p))
    {
        boost::filesystem::create_directory(p);
    }

    p /= "geanyastyle.conf";

    m_filePath = p.c_str();
}

Config::~Config()
{
    delete m_aconfig;

    delete m_lconfig;
}

std::string Config::getAstyleConfig() const
{
    return m_aconfig->serialize();
}

void Config::loadSettings()
{
    try
    {
        m_lconfig->readFile(m_filePath.c_str());
    }
    catch(lc::ParseException& ex)
    {
        std::cout << "An parser error occured: " << ex.getError() << std::endl;
        std::cout << "Message: " << ex.what() << std::endl;
        std::cout << "Line: " << ex.getLine() << std::endl;

    }
    catch(lc::FileIOException& ex) // no config file found
    {
        // add default values to settings
        createDefault();

        // write config file with default settings
        // [TODO] this can be fatal, writeFile throws exceptions, but those are
        // not catched, fix me
        m_lconfig->writeFile(m_filePath.c_str());
    }

    // lookup settings
    try
    {
        if(m_lconfig->exists("Astyle.bracketStyle"))
        {
            m_aconfig->setBracketStyle(m_lconfig->lookup("Astyle.bracketStyle"));
        }

        if(m_lconfig->exists("indentStyle"))
        {
            m_aconfig->setIndentStyle(m_lconfig->lookup("indentStyle"));
        }

        if(m_lconfig->exists("indentLength"))
        {
            m_aconfig->setIndentLength(m_lconfig->lookup("indentLength"));
        }

        if(m_lconfig->exists("indentClasses"))
        {
            m_aconfig->setIndentClasses(m_lconfig->lookup("indentClasses"));
        }

        if(m_lconfig->exists("indentSwitches"))
        {
            m_aconfig->setIndentSwitches(m_lconfig->lookup("indentSwitches"));
        }

        if(m_lconfig->exists("indentNamespaces"))
        {
            m_aconfig->setIndentNamespaces(m_lconfig->lookup("indentNamespaces"));
        }

        if(m_lconfig->exists("indentLabels"))
        {
            m_aconfig->setIndentLabels(m_lconfig->lookup("indentLabels"));
        }

        if(m_lconfig->exists("indentPreprocessor"))
        {
            m_aconfig->setIndentPreprocessor(m_lconfig->lookup("indentPreprocessor"));
        }

        if(m_lconfig->exists("indentCol1Comments"))
        {
            m_aconfig->setIndentCol1Comments(m_lconfig->lookup("indentCol1Comments"));
        }

        if(m_lconfig->exists("minConditionalIndent"))
        {
            m_aconfig->setMinConditionalIndent(m_lconfig->lookup("minConditionalIndent"));
        }

        if(m_lconfig->exists("maxInStatementIndent"))
        {
            m_aconfig->setMaxInStatementIndent(m_lconfig->lookup("maxInStatementIndent"));
        }

        if(m_lconfig->exists("breakBlocks"))
        {
            m_aconfig->setBreakBlocks(m_lconfig->lookup("breakBlocks"));
        }

        if(m_lconfig->exists("breakBlocksAll"))
        {
            m_aconfig->setBreakBlocksAll(m_lconfig->lookup("breakBlocksAll"));
        }

        if(m_lconfig->exists("padOper"))
        {
            m_aconfig->setPadOper(m_lconfig->lookup("padOper"));
        }

        if(m_lconfig->exists("padParen"))
        {
            m_aconfig->setPadParen(m_lconfig->lookup("padParen"));
        }

        if(m_lconfig->exists("padParenOut"))
        {
            m_aconfig->setPadParenOut(m_lconfig->lookup("padParenOut"));
        }

        if(m_lconfig->exists("padParenIn"))
        {
            m_aconfig->setPadParenIn(m_lconfig->lookup("padParenIn"));
        }

        if(m_lconfig->exists("padHeader"))
        {
            m_aconfig->setPadHeader(m_lconfig->lookup("padHeader"));
        }

        if(m_lconfig->exists("unpadParen"))
        {
            m_aconfig->setUnpadParen(m_lconfig->lookup("unpadParen"));
        }

        if(m_lconfig->exists("deleteEmptyLines"))
        {
            m_aconfig->setDeleteEmptyLines(m_lconfig->lookup("deleteEmptyLines"));
        }

        if(m_lconfig->exists("fillEmptyLines"))
        {
            m_aconfig->setFillEmptyLines(m_lconfig->lookup("fillEmptyLines"));
        }

        if(m_lconfig->exists("breakClosingBrackets"))
        {
            m_aconfig->setBreakClosingBrackets(m_lconfig->lookup("breakClosingBrackets"));
        }

        if(m_lconfig->exists("breakElseifs"))
        {
            m_aconfig->setBreakElseifs(m_lconfig->lookup("breakElseifs"));
        }

        if(m_lconfig->exists("addBrackets"))
        {
            m_aconfig->setAddBrackets(m_lconfig->lookup("addBrackets"));
        }

        if(m_lconfig->exists("addOneLineBrackets"))
        {
            m_aconfig->setAddOneLineBrackets(m_lconfig->lookup("addOneLineBrackets"));
        }

        if(m_lconfig->exists("keepOneLineBlocks"))
        {
            m_aconfig->setKeepOneLineBlocks(m_lconfig->lookup("keepOneLineBlocks"));
        }

        if(m_lconfig->exists("keepOneLineStatements"))
        {
            m_aconfig->setKeepOneLineStatements(m_lconfig->lookup("keepOneLineStatements"));
        }

        if(m_lconfig->exists("convertTabs"))
        {
            m_aconfig->setConvertTabs(m_lconfig->lookup("convertTabs"));
        }

        if(m_lconfig->exists("alignPointer"))
        {
            m_aconfig->setAlignPointer(m_lconfig->lookup("alignPointer"));
        }

        if(m_lconfig->exists("alignReference"))
        {
            m_aconfig->setAlignReference(m_lconfig->lookup("alignReference"));
        }

        if(m_lconfig->exists("fileMode"))
        {
            m_aconfig->setFileMode(m_lconfig->lookup("fileMode"));
        }
    }
    catch(lc::SettingNotFoundException& ex)
    {
        // this cannot happen
    }
}

void Config::saveSettings()
{
    try
    {
        m_lconfig->writeFile(m_filePath.c_str());
    }
    catch(lc::FileIOException& ex)
    {
        std::cerr << "Cannot write file!!!" << std::endl;
    }
}

void Config::createDefault()
{
    // [TODO] This is a quick&dirty hack, could be exported to separate class.
    // root setting
    lcs& root = m_lconfig->getRoot();

    // astyle option group
    lcs& astyle = root.add("Astyle", lcs::TypeGroup);

    // bracket style options
    lcs& bracketStyle = astyle.add("bracketStyle", lcs::TypeInt);
    bracketStyle = m_aconfig->getBracketStyle();

    // tab options
    lcs& indentStyle = astyle.add("indentStyle", lcs::TypeInt);
    indentStyle = m_aconfig->getIndentStyle();

    lcs& indentLength = astyle.add("indentLength", lcs::TypeInt);
    indentLength = m_aconfig->getIndentLength();

    // indentation options
    lcs& indentClasses = astyle.add("indentClasses", lcs::TypeBoolean);
    indentClasses = m_aconfig->getIndentClasses();

    lcs& indentSwitches = astyle.add("indentSwitches", lcs::TypeBoolean);
    indentSwitches = m_aconfig->getIndentClasses();

    lcs& indentNamespaces = astyle.add("indentNamespaces", lcs::TypeBoolean);
    indentNamespaces = m_aconfig->getIndentNamespaces();

    lcs& indentLabels = astyle.add("indentLabels", lcs::TypeBoolean);
    indentLabels = m_aconfig->getIndentLabels();

    lcs& indentPreprocessor = astyle.add("indentPreprocessor", lcs::TypeBoolean);
    indentPreprocessor = m_aconfig->getIndentPreprocessor();

    lcs& indentCol1Comments = astyle.add("indentCol1Comments", lcs::TypeBoolean);
    indentCol1Comments = m_aconfig->getIndentCol1Comments();

    lcs& minConditionalIndent = astyle.add("minConditionalIndent", lcs::TypeInt);
    minConditionalIndent = m_aconfig->getMinConditionalIndent();

    lcs& maxInStatementIndent = astyle.add("maxInStatementIndent", lcs::TypeInt);
    maxInStatementIndent = m_aconfig->getMaxInStatementIndent();

    // padding options
    lcs& breakBlocks = astyle.add("breakBlocks", lcs::TypeBoolean);
    breakBlocks = m_aconfig->getBreakBlocks();

    lcs& breakBlocksAll = astyle.add("breakBlocksAll", lcs::TypeBoolean);
    breakBlocksAll = m_aconfig->getBreakBlocksAll();

    lcs& padOper = astyle.add("padOper", lcs::TypeBoolean);
    padOper = m_aconfig->getPadOper();

    lcs& padParen = astyle.add("padParen", lcs::TypeBoolean);
    padParen = m_aconfig->getPadParen();

    lcs& padParenOut = astyle.add("padParenOut", lcs::TypeBoolean);
    padParenOut = m_aconfig->getPadParenOut();

    lcs& padParenIn = astyle.add("padParenIn", lcs::TypeBoolean);
    padParenIn = m_aconfig->getPadParenIn();

    lcs& padHeader = astyle.add("padHeader", lcs::TypeBoolean);
    padHeader = m_aconfig->getPadHeader();

    lcs& unpadParen = astyle.add("unpadParen", lcs::TypeBoolean);
    unpadParen = m_aconfig->getUnpadParen();

    lcs& deleteEmptyLines = astyle.add("deleteEmptyLines", lcs::TypeBoolean);
    deleteEmptyLines = m_aconfig->getDeleteEmptyLines();

    lcs& fillEmptyLines = astyle.add("fillEmptyLines", lcs::TypeBoolean);
    fillEmptyLines = m_aconfig->getFillEmptyLines();

    lcs& breakClosingBrackets = astyle.add("breakClosingBrackets", lcs::TypeBoolean);
    breakClosingBrackets = m_aconfig->getBreakClosingBrackets();

    lcs& breakElseifs = astyle.add("breakElseifs", lcs::TypeBoolean);
    breakElseifs = m_aconfig->getBreakElseifs();

    lcs& addBrackets = astyle.add("addBrackets", lcs::TypeBoolean);
    addBrackets = m_aconfig->getAddBrackets();

    lcs& addOneLineBrackets = astyle.add("addOneLineBrackets", lcs::TypeBoolean);
    addOneLineBrackets = m_aconfig->getAddOneLineBrackets();

    lcs& keepOneLineBlocks = astyle.add("keepOneLineBlocks", lcs::TypeBoolean);
    keepOneLineBlocks = m_aconfig->getKeepOneLineBlocks();

    lcs& keepOneLineStatements = astyle.add("keepOneLineStatements", lcs::TypeBoolean);
    keepOneLineStatements = m_aconfig->getKeepOneLineStatements();

    lcs& convertTabs = astyle.add("convertTabs", lcs::TypeBoolean);
    convertTabs = m_aconfig->getConvertTabs();

    lcs& alignPointer = astyle.add("alignPointer", lcs::TypeInt);
    alignPointer = m_aconfig->getAlignPointer();

    lcs& alignReference = astyle.add("alignReference", lcs::TypeInt);
    alignReference = m_aconfig->getAlignReference();

    lcs& fileMode = astyle.add("fileMode", lcs::TypeInt);
    fileMode = m_aconfig->getFileMode();
}
