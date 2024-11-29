//
// Created by lenovo on 2024/11/29.
//

#include "Farm.h"
#include "MethodForecastAmout.h"
#include "MethodForecastPrice.h"
#include "MethodSolveResult.h"

void Farm::setData() { /*略*/ }

float Farm::ForecastAmount(MethodForecastAmout& methodForecastAmout) const {
    return methodForecastAmout.solve(history, N);
}

float Farm::ForecastPrice(MethodForecastPrice& methodForecastPrice) const {
    return methodForecastPrice.solve(history, N);
}

float Farm::Income(MethodForecastAmout& methodForecastAmout, MethodForecastPrice& methodForecastPrice,
                   MethodSolveResult& methodSolveResult) const {
    float result = ForecastAmount(methodForecastAmout) * ForecastPrice(methodForecastPrice);
    return methodSolveResult.solve(result, history, N);
}