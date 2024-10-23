//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_COMMANDPARSER_H
#define CODING1_COMMANDPARSER_H

#include "CommandPara.h"

class CommandParser {
public:
    static vector<CommandPara> divideCommand(const vector<string>& commandList);
private:
    static bool isCommandHead(const string& commanditem);
};

#endif //CODING1_COMMANDPARSER_H
