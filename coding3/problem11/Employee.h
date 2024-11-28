//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM11_EMPLOYEE_H
#define PROBLEM11_EMPLOYEE_H


class Employee {
public:
    Employee(long _mWage);
    virtual ~Employee() = default;
    virtual long Award(long base) = 0;
protected:
    long mWage;
};


#endif //PROBLEM11_EMPLOYEE_H
