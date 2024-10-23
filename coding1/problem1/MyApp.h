//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_MYAPP_H
#define CODING1_MYAPP_H

#include <string>
#include <vector>
using std::string;
using std::vector;
class Operation;

class MyApp {
public:
    MyApp();
    void receiveCommand(int argc, char* argv[]);
    [[nodiscard]] int executeCommand() const;
private:
    vector<string> mCommandList;
    Operation * mOperationAdd;
    Operation * mOperationRed;
    Operation * mOperationConcat;
    Operation * mOperationHelp;
};

#endif //CODING1_MYAPP_H
