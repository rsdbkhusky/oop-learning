//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM11_STUFF_H
#define PROBLEM11_STUFF_H


#include "Employee.h"

class Stuff: public Employee {
public:
    Stuff(long _mWage);
    virtual ~Stuff() override = default;
    virtual long Award(long base) override;
};


#endif //PROBLEM11_STUFF_H
