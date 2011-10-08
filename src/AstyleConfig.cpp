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
    m_indentClasses = false;
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

int AstyleConfig::getBracketStyle() const
{
    return static_cast<int>(m_bracketStyle);
}

void AstyleConfig::setBracketStyle(int style)
{
    switch (style)
    {
    case 1:
        m_bracketStyle = bracketDefault;
        break;
    case 2:
        m_bracketStyle = bracketAllman;
        break;
    case 3:
        m_bracketStyle = bracketJava;
        break;
    case 4:
        m_bracketStyle = bracketKr;
        break;
    case 5:
        m_bracketStyle = bracketStroustrup;
        break;
    case 6:
        m_bracketStyle = bracketWhitesmith;
        break;
    case 7:
        m_bracketStyle = bracketBanner;
        break;
    case 8:
        m_bracketStyle = bracketGnu;
        break;
    case 9:
        m_bracketStyle = bracketLinux;
        break;
    case 10:
        m_bracketStyle = bracketHorstmann;
        break;
    case 11:
        m_bracketStyle = bracketOnebts;
        break;
    case 12:
        m_bracketStyle = bracketPico;
        break;
    case 13:
        m_bracketStyle = bracketLisp;
        break;
    default:
        m_bracketStyle = bracketDefault;
        break;
    };
}

int AstyleConfig::getIndentStyle() const
{
    return static_cast<int>(m_indentStyle);
}

void AstyleConfig::setIndentStyle(int style)
{
    switch (style)
    {
    case 1:
        m_indentStyle = indentTabs;
        break;
    case 2:
        m_indentStyle = indentSpaces;
        break;
    case 3:
        m_indentStyle = indentForceTabs;
        break;
    default:
        m_indentStyle = indentSpaces;
        break;
    };
}

int AstyleConfig::getIndentLength() const
{
    return m_indentLength;
}

void AstyleConfig::setIndentLength(int length)
{
    m_indentLength = length;
}

bool AstyleConfig::getIndentClasses() const
{
    return m_indentClasses;
}

void AstyleConfig::setIndentClasses(bool flag)
{
    m_indentClasses = flag;
}

bool AstyleConfig::getIndentSwitches() const
{
    return m_indentSwitches;
}

void AstyleConfig::setIndentSwitches(bool flag)
{
    m_indentSwitches = flag;
}

bool AstyleConfig::getIndentCases() const
{
    return m_indentCases;
}

void AstyleConfig::setIndentCases(bool flag)
{
    m_indentCases = flag;

}

bool AstyleConfig::getIndentNamespaces() const
{
    return m_indentNamespaces;
}

void AstyleConfig::setIndentNamespaces(bool flag)
{
    m_indentNamespaces = flag;
}

bool AstyleConfig::getIndentLabels() const
{
    return m_indentLabels;
}

void AstyleConfig::setIndentLabels(bool flag)
{
    m_indentLabels = flag;
}

bool AstyleConfig::getIndentPreprocessor() const
{
    return m_indentPreprocessor;
}

void AstyleConfig::setIndentPreprocessor(bool flag)
{
    m_indentPreprocessor = flag;
}

bool AstyleConfig::getIndentCol1Comments() const
{
    return m_indentCol1Comments;
}

void AstyleConfig::setIndentCol1Comments(bool flag)
{
    m_indentCol1Comments = flag;
}

int AstyleConfig::getMinConditionalIndent() const
{
    return static_cast<int>(m_minConditionalIndent);
}

void AstyleConfig::setMinConditionalIndent(int indent)
{
    switch (indent)
    {
    case 0:
        m_minConditionalIndent = minCondIndentNone;
        break;
    case 1:
        m_minConditionalIndent = minCondIndentOne;
        break;
    case 2:
        m_minConditionalIndent = minCondIndentTwo;
        break;
    case 3:
        m_minConditionalIndent = minCondIndentOneHalf;
        break;
    default:
        m_minConditionalIndent = minCondIndentTwo;
        break;
    };
}

int AstyleConfig::getMaxInStatementIndent() const
{
    return m_maxInStatementIndent;
}

void AstyleConfig::setMaxInStatementIndent(int indent)
{
    m_maxInStatementIndent = indent;
}

bool AstyleConfig::getBreakBlocks() const
{
    return m_breakBlocks;
}

void AstyleConfig::setBreakBlocks(bool flag)
{
    m_breakBlocks = flag;
}

bool AstyleConfig::getBreakBlocksAll() const
{
    return m_breakBlocksAll;
}

void AstyleConfig::setBreakBlocksAll(bool flag)
{
    m_breakBlocksAll = flag;
}

bool AstyleConfig::getPadOper() const
{
    return m_padOper;
}

void AstyleConfig::setPadOper(bool flag)
{
    m_padOper = flag;
}

bool AstyleConfig::getPadParen() const
{
    return m_padParen;
}

void AstyleConfig::setPadParen(bool flag)
{
    m_padParen = flag;
}

bool AstyleConfig::getPadParenOut() const
{
    return m_padParenOut;
}

void AstyleConfig::setPadParenOut(bool flag)
{
    m_padParenOut = flag;
}

bool AstyleConfig::getPadParenIn() const
{
    return m_padParenIn;
}

void AstyleConfig::setPadParenIn(bool flag)
{
    m_padParenIn = flag;
}

bool AstyleConfig::getPadHeader() const
{
    return m_padHeader;
}

void AstyleConfig::setPadHeader(bool flag)
{
    m_padHeader = flag;
}

bool AstyleConfig::getUnpadParen() const
{
    return m_unpadParen;
}

void AstyleConfig::setUnpadParen(bool flag)
{
    m_unpadParen = flag;
}

bool AstyleConfig::getDeleteEmptyLines() const
{
    return m_deleteEmptyLines;
}

void AstyleConfig::setDeleteEmptyLines(bool flag)
{
    m_deleteEmptyLines = flag;
}

bool AstyleConfig::getFillEmptyLines() const
{
    return m_fillEmptyLines;
}

void AstyleConfig::setFillEmptyLines(bool flag)
{
    m_fillEmptyLines = flag;
}

bool AstyleConfig::getBreakClosingBrackets() const
{
    return m_breakClosingBrackets;
}

void AstyleConfig::setBreakClosingBrackets(bool flag)
{
    m_breakClosingBrackets = flag;
}

bool AstyleConfig::getBreakElseifs() const
{
    return m_breakElseifs;
}

void AstyleConfig::setBreakElseifs(bool flag)
{
    m_breakElseifs = flag;
}

bool AstyleConfig::getAddBrackets() const
{
    return m_addBrackets;
}

void AstyleConfig::setAddBrackets(bool flag)
{
    m_addBrackets = flag;
}

bool AstyleConfig::getAddOneLineBrackets() const
{
    return m_addOneLineBrackets;
}

void AstyleConfig::setAddOneLineBrackets(bool flag)
{
    m_addOneLineBrackets = flag;
}

bool AstyleConfig::getKeepOneLineBlocks() const
{
    return m_keepOneLineBlocks;
}

void AstyleConfig::setKeepOneLineBlocks(bool flag)
{
    m_keepOneLineBlocks = flag;
}

bool AstyleConfig::getKeepOneLineStatements() const
{
    return m_keepOneLineStatements;
}

void AstyleConfig::setKeepOneLineStatements(bool flag)
{
    m_keepOneLineStatements = flag;
}

bool AstyleConfig::getConvertTabs() const
{
    return m_convertTabs;
}

void AstyleConfig::setConvertTabs(bool flag)
{
    m_convertTabs = flag;
}

int AstyleConfig::getAlignPointer() const
{
    return static_cast<int>(m_alignPointer);
}

void AstyleConfig::setAlignPointer(int aptr)
{
    switch (aptr)
    {
    case 1:
        m_alignPointer = pointerNone;
        break;
    case 2:
        m_alignPointer = pointerType;
        break;
    case 3:
        m_alignPointer = pointerMiddle;
        break;
    case 4:
        m_alignPointer = pointerName;
        break;
    default:
        m_alignPointer = pointerNone;
        break;
    };
}

int AstyleConfig::getAlignReference() const
{
    return static_cast<int>(m_alignReference);
}

void AstyleConfig::setAlignReference(int aref)
{
    switch (aref)
    {
    case 1:
        m_alignReference = referenceNone;
        break;
    case 2:
        m_alignReference = referenceType;
        break;
    case 3:
        m_alignReference = referenceMiddle;
        break;
    case 4:
        m_alignReference = referenceName;
        break;
    default:
        m_alignReference = referenceNone;
        break;
    };
}

int AstyleConfig::getFileMode() const
{
    return static_cast<int>(m_fileMode);
}

void AstyleConfig::setFileMode(int mode)
{
    switch (mode)
    {
    case 1:
        m_fileMode = modeCpp;
        break;
    case 2:
        m_fileMode = modeCsharp;
        break;
    case 3:
        m_fileMode = modeJava;
        break;
    };
}


std::string AstyleConfig::serialize() const
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
    if(m_indentClasses)
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

std::string AstyleConfig::intToString(const int num) const
{
    std::stringstream stream;

    stream << num;

    return stream.str();
}
