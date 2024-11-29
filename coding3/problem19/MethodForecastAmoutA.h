//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_METHODFORECASTAMOUTA_H
#define PROBLEM19_METHODFORECASTAMOUTA_H

#include "MethodForecastAmout.h"

class MethodForecastAmoutA: public MethodForecastAmout {
public:
    virtual float solve(const Data* history, int years) override;
};


#endif //PROBLEM19_METHODFORECASTAMOUTA_H
