//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_METHODFORECASTAMOUTB_H
#define PROBLEM19_METHODFORECASTAMOUTB_H


#include "MethodForecastAmout.h"

class MethodForecastAmoutB: public MethodForecastAmout {
public:
    virtual float solve(const Data* history, int years) override;
};


#endif //PROBLEM19_METHODFORECASTAMOUTB_H
