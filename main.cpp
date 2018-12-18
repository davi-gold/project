#include <iostream>
#include <fstream>
#include <list>
#include "Translator.h"

using namespace std;


int main() {
    string str = "rudder = (h0 – heading)/20";
    map<string, Command> symbolTable;
    Translator *t = new Translator(symbolTable);
    list<string> s;
    s = t->lexer(str);
    list<string>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << endl;
    return 0;
}
//    string input = "This is a test";
//    // open in write mode
//    ofstream oFile;
//    oFile.open("test.txt");
//    oFile << input;
//    oFile.close();
//
//    // open in read mode
//    ifstream iFile;
//    iFile.open("test.txt");
//    list<string> str;
//    map<string, Command> symbolTable;
//    Translator *t = new Translator(symbolTable);
//    str = trnsltr->lexer(iFile);
//    list<string>::iterator iter;
//
//    for (iter = str.begin(); iter != str.end(); iter++)
//        cout << *iter << endl;
//    return 0;
//}