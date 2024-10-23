//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_OPERATIONCONCAT_H
#define CODING1_OPERATIONCONCAT_H

#include "Operation.h"

class OperationConcat: public Operation {
public:
    void processPara(const CommandPara& cp) override;
};

#endif //CODING1_OPERATIONCONCAT_H
