//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_OPERATION_H
#define CODING1_OPERATION_H

#include "CommandPara.h"

class Operation {
public:
    virtual void processPara(const CommandPara& cp) {}
};

#endif //CODING1_OPERATION_H
