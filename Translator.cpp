//
// Created by David Goldberg on 2018-12-17.
//
#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#include <fstream>
#include "Command.h"
#include "Translator.h"
#include "openServerCommand.h"
#include "connectCommand.h"
#include "varCommand.h"

using namespace std;
#define EQUALS '='
#define ENDOFSTRING '\0'
#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define PATHSIGN '"'



/**
 * This is a constructor
 * @param symbolTable
 */
Translator::Translator(map<string, Command> symbolTable) {
    this->symbolTable = symbolTable;
}


/**
 * This function breaks the text into words (expressions) in a list of strings
 * @param file
 * @return list of expression
 */

list<string> Translator::lexer(string str) {
    string strTmp; // temporary string for holding the chars
    list<string> strLst; // the return value
    int i = 0; // index
    // as long as this is not the end of the string
    while (str[i] != ENDOFSTRING) {
        // as long as the current char is not whitespace or end of string
        while (isspace(str[i]) == 0 && str[i] != ENDOFSTRING) {
            strTmp.push_back(str[i]); // push the char to the word
            i++;
        }
        strLst.push_back(strTmp); // push the word to the list
        strTmp = "";
        if (isspace(str[i]) != 0)  // if the current char is a whitespace
            i++;
    }
    return strLst;
}


/**
 * This function breaks the text into words (expressions) in a list of strings
 * @param file
 * @return list of expression
 */
//
//list<string> Translator::lexer(string str) {
//    bool operatorFlag = false;
//    string strTmp; // temporary string for holding the chars
//    list<string> strLst;
//    int i = 0;
//    // as long as this is not the end of the string
//    while (str[i] != ENDOFSTRING) {
//        // as long as the char is not whitespace, end of string, equals or comma
//        while (isspace(str[i]) == 0 && str[i] != ENDOFSTRING && str[i] != EQUALS && str[i] != ',') {
//            // if the current char is an arithmetic operator - insert the operands around it to the same cell
//            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
//                if (str[i + 1] != '+' && str[i + 1] != EQUALS) { // excludes cases like 'x++' or 'x += 5'
//                    int operatorIndex = i;
//                    while (isdigit(str[i]) == 0) // as long as the char is not a digit (getting the left operand)
//                        i--;
//                    while (isdigit(str[i]) !=
//                           0) // as long as the char is a digit (getting all the digits of left operand)
//                        i--;
//                    int leftOperandIndex = i; // start of left operand
//                    i = operatorIndex;
//                    while (isdigit(str[i]) == 0) // as long as the char is not a digit (getting the right operand)
//                        i++;
//                    while (isdigit(str[i]) !=
//                           0) // as long as the char is a digit (getting all the digits of right operand)
//                        i++;
//                    int rightOperandIndex = i; // end of right operand
//                    if (operatorFlag == false) {
//                        strLst.pop_back();
//                    }
//                    for (int i = leftOperandIndex; i <= rightOperandIndex; i++) {
//                        if (isspace(str[i]) == 0) // if the char is not a whitespace
//                            strTmp.push_back(str[i]);
//                    }
//                    operatorFlag = true;
//                }
//            } else { // if it is not an operator
//                strTmp.push_back(str[i]); // push the char to the word
//                i++;
//                operatorFlag = false;
//            }
//        }
//        strLst.push_back(strTmp); // push the word to the list
//        strTmp = "";
//        if (isspace(str[i]) != 0 || str[i] == EQUALS)  // if the current char is a whitespace or equals
//            i++;
//    }
//    return strLst;
//}
//
//void Translator::parser(list<string> strLst) {
//        map<string, Command> symbolTable;
//        // updating command map
//        symbolTable = {{"openDataServer", openServerCommand()},
//                       {"connect",        connectCommand()},
//                       {"var",            varCommand()}};
//
//        // for every string in list
//        iterator<string> iter;
//        for (int i = 0; i < strLst.size(); i++) {
//            // search for the command in the map
//            auto search = symbolTable.find(strLst.get(i));
//            // if the command is not found
//}