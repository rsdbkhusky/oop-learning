//
// Created by lenovo on 2024/10/18.
//

#include <iostream>
#include <string>
#include <cassert>
#include "OperationRed.h"
using std::cout;
using std::endl;
using std::stoi;

void OperationRed::processPara(const CommandPara &cp) {
    assert(cp.getParaData().size() == 1);
    int fir = stoi(cp.getParaData()[0]);
    cout << 500 - fir << endl;
}
