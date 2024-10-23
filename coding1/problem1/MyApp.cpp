//
// Created by lenovo on 2024/10/18.
//

#include "MyApp.h"
#include "CommandParser.h"
#include "OperationAdd.h"
#include "OperationRed.h"
#include "OperationConcat.h"
#include "OperationHelp.h"

MyApp::MyApp() {
    mOperationAdd = new OperationAdd;
    mOperationRed = new OperationRed;
    mOperationConcat = new OperationConcat;
    mOperationHelp = new OperationHelp;
}
void MyApp::receiveCommand(int argc, char **argv) {
    mCommandList.clear();
    for (int i = 0; i < argc; ++i) {
        mCommandList.emplace_back(argv[i]);
    }
}
int MyApp::executeCommand() const {
    vector<CommandPara> cpl = CommandParser::divideCommand(mCommandList);
    for (const auto& cp: cpl) {
        if (cp.getParaHead() == string("-a")) {
            mOperationAdd -> processPara(cp);
        } else if (cp.getParaHead() == string("-r")) {
            mOperationRed -> processPara(cp);
        } else if (cp.getParaHead() == string("-c")) {
            mOperationConcat -> processPara(cp);
        } else if (cp.getParaHead() == string("-h")) {
            mOperationHelp -> processPara(cp);
        }
    }
    return 0;
}