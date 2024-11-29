//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_METHODFORECASTPRICE_H
#define PROBLEM19_METHODFORECASTPRICE_H

class Data;

class MethodForecastPrice {
public:
    virtual ~MethodForecastPrice();
    virtual float solve(const Data* history, int years);
};


#endif //PROBLEM19_METHODFORECASTPRICE_H
