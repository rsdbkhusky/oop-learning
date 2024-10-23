//
// Created by lenovo on 2024/10/18.
//

#include <iostream>
#include <cassert>
#include "OperationConcat.h"
using std::cout;
using std::endl;

void OperationConcat::processPara(const CommandPara &cp) {
    assert(cp.getParaData().size() == 2);
    cout << cp.getParaData()[0] + cp.getParaData()[1] << endl;
}
