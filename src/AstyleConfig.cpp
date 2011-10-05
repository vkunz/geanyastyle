/*
 * AstyleConfig.cpp - Arctic Style plugin for the Geany IDE
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

#include <sstream>
#include <string>

#include "AstyleConfig.hpp"

AstyleConfig::AstyleConfig()
{
    // init default values
    // bracket style options
    m_bracketStyle = bracketDefault;

    // tab options
    m_indentStyle = indentSpaces;
    m_indentLength = 4;

    // indentation options
    m_indentClass = false;
    m_indentSwitches = false;
    m_indentCases = false;
    m_indentNamespaces = false;
    m_indentLabels = false;
    m_indentPreprocessor = false;
    m_indentCol1Comments = false;
    m_minConditionalIndent = minCondIndentTwo;
    m_maxInStatementIndent = 40;

    // padding options
    m_breakBlocks = false;
    m_breakBlocksAll = false;
    m_padOper = false;
    m_padParen = false;
    m_padParenOut = false;
    m_padParenIn = false;
    m_padHeader = false;
    m_unpadParen = false;
    m_deleteEmptyLines = false;
    m_fillEmptyLines = false;

    // formatting options
    m_breakClosingBrackets = false;
    m_breakElseifs = false;
    m_addBrackets = false;
    m_addOneLineBrackets = false;
    m_keepOneLineBlocks = false;
    m_keepOneLineStatements = false;
    m_convertTabs = false;
    m_alignPointer = pointerNone;
    m_alignReference = referenceNone;

    // file mode
    m_fileMode = modeCpp;
}

AstyleConfig::~AstyleConfig()
{
}

std::string AstyleConfig::serialize()
{
    std::string config;
    std::string separator = ",";

    // bracket options
    switch (m_bracketStyle)
    {
    case bracketDefault:
        break;
    case bracketAllman:
        config += "style=allman";
        config += separator;
        break;
    case bracketJava:
        config += "style=java";
        config += separator;
        break;
    case bracketKr:
        config += "style=kr";
        config += separator;
        break;
    case bracketStroustrup:
        config += "style=stroustrup";
        config += separator;
        break;
    case bracketWhitesmith:
        config += "style=whitesmith";
        config += separator;
        break;
    case bracketBanner:
        config += "style=banner";
        config += separator;
        break;
    case bracketGnu:
        config += "style=gnu";
        config += separator;
        break;
    case bracketLinux:
        config += "style=linux";
        config += separator;
        break;
    case bracketHorstmann:
        config += "style=horstmann";
        config += separator;
        break;
    case bracketOnebts:
        config += "style=1tbs";
        config += separator;
        break;
    case bracketPico:
        config += "style=pico";
        config += separator;
        break;
    case bracketLisp:
        config += "style=lisp";
        config += separator;
        break;
    default:
        break;
    };

    // tab options
    switch (m_indentStyle)
    {
    case indentTabs:
        config += ("indent=tabs=" + intToString(m_indentLength));
        config += separator;
        break;
    case indentSpaces:
        config += ("indent=spaces=" + intToString(m_indentLength));
        config += separator;
        break;
    case indentForceTabs:
        config += ("indent=force-tab=" + intToString(m_indentLength));
        config += separator;
        break;
    default:
        config += ("indent=spaces=" + intToString(m_indentLength));
        config += separator;
        break;
    };

    // indentation options
    if(m_indentClass)
    {
        config += "indent-classes";
        config += separator;
    }

    if(m_indentSwitches)
    {
        config += "indent-switches";
        config += separator;
    }

    if(m_indentCases)
    {
        config += "indent-cases";
        config += separator;
    }

    if(m_indentNamespaces)
    {
        config += "indent-namespaces";
        config += separator;
    }

    if(m_indentLabels)
    {
        config += "indent-labels";
        config += separator;
    }

    if(m_indentPreprocessor)
    {
        config += "indent-preprocessor";
        config += separator;
    }

    if(m_indentCol1Comments)
    {
        config += "indent-col1-comments";
        config += separator;
    }

    config += "min-conditional-indent=" + intToString(m_minConditionalIndent);
    config += separator;

    config += "max-instatement-indent=" + intToString(m_maxInStatementIndent);
    config += separator;

    // padding options
    if(m_breakBlocks)
    {
        config += "break-blocks";
        config += separator;
    }

    if(m_breakBlocksAll)
    {
        config += "break-blocks=all";
        config += separator;
    }

    if(m_padOper)
    {
        config += "pad-oper";
        config += separator;
    }

    if(m_padParen)
    {
        config += "pad-paren";
        config += separator;
    }

    if(m_padParenOut)
    {
        config += "pad-paren-out";
        config += separator;
    }

    if(m_padParenIn)
    {
        config += "pad-paren-in";
        config += separator;
    }

    if(m_padHeader)
    {
        config += "pad-header";
        config += separator;
    }

    if(m_unpadParen)
    {
        config += "unpad-paren";
        config += separator;
    }


    if(m_deleteEmptyLines)
    {
        config += "delete-empty-lines";
        config += separator;
    }

    if(m_fillEmptyLines)
    {
        config += "fill-empty-lines";
        config += separator;
    }

    if(m_breakClosingBrackets)
    {
        config += "break-closing-brackets";
        config += separator;
    }

    if(m_breakElseifs)
    {
        config += "break-elseifs";
        config += separator;
    }

    if(m_addBrackets)
    {
        config += "add-brackets";
        config += separator;
    }

    if(m_addOneLineBrackets)
    {
        config += "add-one-line-brackets";
        config += separator;
    }

    if(m_keepOneLineBlocks)
    {
        config += "keep-one-line-blocks";
        config += separator;
    }

    if(m_keepOneLineStatements)
    {
        config += "keep-one-line-statements";
        config += separator;
    }

    if(m_convertTabs)
    {
        config += "convert-tabs";
        config += separator;
    }

    switch (m_alignPointer)
    {
    case pointerNone:
        break;
    case pointerType:
        config += "align-pointer=type";
        config += separator;
        break;
    case pointerMiddle:
        config += "align-pointer=middle";
        config += separator;
        break;
    case pointerName:
        config += "align-pointer=name";
        config += separator;
    default:
        break;
    };

    switch (m_alignReference)
    {
    case referenceNone:
        break;
    case referenceType:
        config += "align-reference=type";
        config += separator;
        break;
    case referenceMiddle:
        config += "align-reference=middle";
        config += separator;
        break;
    case referenceName:
        config += "align-reference=name";
        config += separator;
    default:
        break;
    };

    switch (m_fileMode)
    {
    case modeCpp:
        config += "mode=c";
        break;
    case modeCsharp:
        config += "mode=cs";
        break;
    case modeJava:
        config += "mode=java";
        break;
    default:
        break;
    }

    return config;
}

std::string AstyleConfig::intToString(int num)
{
    std::stringstream stream;

    stream << num;

    return stream.str();
}
