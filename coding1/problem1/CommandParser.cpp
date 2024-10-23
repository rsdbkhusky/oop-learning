//
// Created by lenovo on 2024/10/18.
//

#include "CommandParser.h"

bool CommandParser::isCommandHead(const string &commanditem) {
    if (commanditem[0] == '-' && commanditem.length() > 1 && commanditem[1] != '-') return true;
    else return false;
}
[[nodiscard]] vector<CommandPara> CommandParser::divideCommand(const vector<string>& commandList) {
    vector<CommandPara> cpl;
    if (commandList.empty()) {
        return cpl;
    }
    int i = 0;
    while (i < commandList.size() && !isCommandHead(commandList[i])) ++i;
    while (i < commandList.size()) {
        CommandPara cp;
        cp.setParaHead(commandList[i]);
        ++i;
        while (i < commandList.size() && !isCommandHead(commandList[i])) {
            cp.addParaData(commandList[i]);
            ++i;
        }
        cpl.push_back(cp);
    }
    return cpl;
}