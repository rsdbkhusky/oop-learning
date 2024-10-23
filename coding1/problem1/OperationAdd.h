//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_OPERATIONADD_H
#define CODING1_OPERATIONADD_H

#include "Operation.h"

class OperationAdd: public Operation {
public:
    void processPara(const CommandPara& cp) override;
};

#endif //CODING1_OPERATIONADD_H
