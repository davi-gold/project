//
// Created by David Goldberg on 2018-12-17.
//
#include <iostream>

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
using namespace std;

class Command {
public:
    void doCommand(list<string> strCommands);
    int execute;
};


#endif //PROJECT_COMMAND_H
