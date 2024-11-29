//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_FARM_H
#define PROBLEM19_FARM_H

#include "Data.h"

class MethodForecastAmout;
class MethodForecastPrice;
class MethodSolveResult;

class Farm {
public:
    static const int N = 20;
    float ForecastAmount(MethodForecastAmout& methodForecastAmout) const;
    float ForecastPrice(MethodForecastPrice& methodForecastPrice) const;
    float Income(MethodForecastAmout& methodForecastAmout, MethodForecastPrice& methodForecastPrice, MethodSolveResult& methodSolveResult) const;
    void setData();
private:
    Data history[N];
};


#endif //PROBLEM19_FARM_H
