//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_METHODFORECASTAMOUT_H
#define PROBLEM19_METHODFORECASTAMOUT_H

class Data;

class MethodForecastAmout {
public:
    virtual ~MethodForecastAmout();
    virtual float solve(const Data* history, int years);
};


#endif //PROBLEM19_METHODFORECASTAMOUT_H
