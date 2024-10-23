//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_OPERATIONRED_H
#define CODING1_OPERATIONRED_H

#include "Operation.h"

class OperationRed: public Operation {
public:
    void processPara(const CommandPara& cp) override;
};

#endif //CODING1_OPERATIONRED_H
