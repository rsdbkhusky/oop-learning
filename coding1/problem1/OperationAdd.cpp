//
// Created by lenovo on 2024/10/18.
//

#include <iostream>
#include <cassert>
#include "OperationAdd.h"
using std::cout;
using std::endl;
using std::stoi;

void OperationAdd::processPara(const CommandPara &cp) {
    assert(cp.getParaData().size() == 2);
    int fir = stoi(cp.getParaData()[0]);
    int sec = stoi(cp.getParaData()[1]);
    cout << fir + sec << endl;
}
