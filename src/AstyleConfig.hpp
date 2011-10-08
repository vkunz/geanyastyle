/*
 * AstyleConfig.hpp - Arctic Style plugin for the Geany IDE
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

#ifndef __ASTYLECONFIG_HPP__
#define __ASTYLECONFIG_HPP__

#include <string>

class AstyleConfig
{
public:
    // ctor
    AstyleConfig();

    // dtor
    ~AstyleConfig();

    enum BracketStyle
    {
        bracketDefault = 1,
        bracketAllman,
        bracketJava,
        bracketKr,
        bracketStroustrup,
        bracketWhitesmith,
        bracketBanner,
        bracketGnu,
        bracketLinux,
        bracketHorstmann,
        bracketOnebts,
        bracketPico,
        bracketLisp
    };

    enum IndentStyle
    {
        indentTabs = 1,
        indentSpaces,
        indentForceTabs
    };

    enum MinCondIndent
    {
        minCondIndentNone = 0,
        minCondIndentOne = 1,
        minCondIndentTwo = 2,
        minCondIndentOneHalf = 3
    };

    enum AlignPointer
    {
        pointerNone = 1,
        pointerType,
        pointerMiddle,
        pointerName
    };

    enum AlignReference
    {
        referenceNone = 1,
        referenceType,
        referenceMiddle,
        referenceName
    };

    enum FileMode
    {
        modeCpp = 1,
        modeCsharp,
        modeJava
    };

    int getBracketStyle() const;
    void setBracketStyle(int style);

    int getIndentStyle() const;
    void setIndentStyle(int style);

    int getIndentLength() const;
    void setIndentLength(int length);

    bool getIndentClasses() const;
    void setIndentClasses(bool flag);

    bool getIndentSwitches() const;
    void setIndentSwitches(bool flag);

    bool getIndentCases() const;
    void setIndentCases(bool flag);

    bool getIndentNamespaces() const;
    void setIndentNamespaces(bool flag);

    bool getIndentLabels() const;
    void setIndentLabels(bool flag);

    bool getIndentPreprocessor() const;
    void setIndentPreprocessor(bool flag);

    bool getIndentCol1Comments() const;
    void setIndentCol1Comments(bool flag);

    int getMinConditionalIndent() const;
    void setMinConditionalIndent(int indent);

    int getMaxInStatementIndent() const;
    void setMaxInStatementIndent(int indent);

    bool getBreakBlocks() const;
    void setBreakBlocks(bool flag);

    bool getBreakBlocksAll() const;
    void setBreakBlocksAll(bool flag);

    bool getPadOper() const;
    void setPadOper(bool flag);

    bool getPadParen() const;
    void setPadParen(bool flag);

    bool getPadParenOut() const;
    void setPadParenOut(bool flag);

    bool getPadParenIn() const;
    void setPadParenIn(bool flag);

    bool getPadHeader() const;
    void setPadHeader(bool flag);

    bool getUnpadParen() const;
    void setUnpadParen(bool flag);

    bool getDeleteEmptyLines() const;
    void setDeleteEmptyLines(bool flag);

    bool getFillEmptyLines() const;
    void setFillEmptyLines(bool flag);

    bool getBreakClosingBrackets() const;
    void setBreakClosingBrackets(bool flag);

    bool getBreakElseifs() const;
    void setBreakElseifs(bool flag);

    bool getAddBrackets() const;
    void setAddBrackets(bool flag);

    bool getAddOneLineBrackets() const;
    void setAddOneLineBrackets(bool flag);

    bool getKeepOneLineBlocks() const;
    void setKeepOneLineBlocks(bool flag);

    bool getKeepOneLineStatements() const;
    void setKeepOneLineStatements(bool flag);

    bool getConvertTabs() const;
    void setConvertTabs(bool flag);

    int getAlignPointer() const;
    void setAlignPointer(int aptr);

    int getAlignReference() const;
    void setAlignReference(int aref);

    int getFileMode() const;
    void setFileMode(int mode);

    // serialize configuration flags/switches
    std::string serialize() const;

private:
    // bracket style options
    // bracket style
    BracketStyle m_bracketStyle;            // --style=

    // tab options
    // indent style
    IndentStyle m_indentStyle;              // --indent=
    int m_indentLength;                     // --indent=...=

    // indentation options
    // indent classes
    bool m_indentClasses;                   // --indent-classes

    // indent switch
    bool m_indentSwitches;                  // --indent-switches

    // indent case
    bool m_indentCases;                     // --indent-cases

    // indent namespaces
    bool m_indentNamespaces;                // --indent-namespaces

    // indent labes
    bool m_indentLabels;                    // --indent-labels

    // indent preprocessor statements
    bool m_indentPreprocessor;              //--indent-preprocessor

    // indent first-column line end comments
    bool m_indentCol1Comments;              // --indent-col1-comments

    // Set the minimal indent that is added when a header is built of multiple lines.
    MinCondIndent m_minConditionalIndent;   // --min-conditional-indent=

    // Set the  maximum of # spaces to indent a continuation line.
    int m_maxInStatementIndent;             // --max-instatement-indent

    // padding options
    // break blocks
    bool m_breakBlocks;                     // --break-blocks

    // break all blocks
    bool m_breakBlocksAll;                  // --break-blocks=ALL

    // pad operators
    bool m_padOper;                         // --pad-oper

    // pad parentheses
    bool m_padParen;                        // --pad-paren

    // pad only outside parenthese
    bool m_padParenOut;                     // --pad-paren-out

    // pad only inside parenthese
    bool m_padParenIn;                      // --pad-paren-in

    // pad header
    bool m_padHeader;                       // --pad-header

    // unpad parentheses
    bool m_unpadParen;                      // --unpad-paren

    // remove empty lines inside function blocks
    bool m_deleteEmptyLines;                // --delete-empty-lines

    // add empty lines
    bool m_fillEmptyLines;                  // --fill-empty-lines

    // formatting options
    // break closing brackets
    bool m_breakClosingBrackets;            // --break-closing-brackets

    // break else if statements
    bool m_breakElseifs;                    // --break-elseifs

    // add brackets to one line blocks
    bool m_addBrackets;                     // --add-brackets

    // add brackets to one line blocks and keep one line
    bool m_addOneLineBrackets;              // --add-one-line-brackets

    // keep one line blocks
    bool m_keepOneLineBlocks;               // --keep-one-line-blocks

    // keep one line statements
    bool m_keepOneLineStatements;           // --keep-one-line-statements

    // convert tabs into spaces
    bool m_convertTabs;                     // --convert-tabs

    // align pointer
    AlignPointer m_alignPointer;            // --align-pointer=

    // align reference
    AlignReference m_alignReference;        // --align-reference=

    // file mode
    FileMode m_fileMode;                    // --mode=

    // intToString conversion helper function
    std::string intToString(const int num) const;
}; // class AstyleConfig

#endif // __ASTYLECONFIG_HPP__
