//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM11_MANAGER_H
#define PROBLEM11_MANAGER_H


#include "Employee.h"

class Manager: public Employee {
public:
    Manager(long _mWage);
    virtual ~Manager() override = default;
    virtual long Award(long base) override;
};


#endif //PROBLEM11_MANAGER_H
