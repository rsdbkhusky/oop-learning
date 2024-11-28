//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM11_DEPARTMENT_H
#define PROBLEM11_DEPARTMENT_H

#include <iostream>
#include "Employee.h"
using std::cout;
using std::endl;

const int N = 3;
class Department {
public:
    Department(long totalProfit): profit(totalProfit) {
        for (int i = 0; i < N; ++i) emps[i] = 0;
    }
    void SetEmployee(Employee* pemp, int index) {
        emps[index] = pemp;
    }
    void ShowEachAward() {
        for (int i = 0; i < N; ++i) cout << emps[i]->Award(profit*0.3/N) << endl;
    }
private:
    Employee* emps[N];
    long profit;
};


#endif //PROBLEM11_DEPARTMENT_H
