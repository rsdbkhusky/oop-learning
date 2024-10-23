//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_OPERATIONHELP_H
#define CODING1_OPERATIONHELP_H

#include "Operation.h"

class OperationHelp: public Operation {
public:
    void processPara(const CommandPara& cp) override;
};

#endif //CODING1_OPERATIONHELP_H
