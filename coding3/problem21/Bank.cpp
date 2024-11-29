//
// Created by lenovo on 2024/11/29.
//

#include "Bank.h"
#include "CodeBlockB.h"
#include "Enterprise.h"

int Bank::Evaluate(Enterprise& ent) {
    int a1 = ent.Func1();
    int a2 = 2;
    int a3 = 3;
    int a4 = 4;
    int a5 = 5;
    int a6 = 6;
    int a7 = 7;
    int a8 = 8;
    vector<int>* pb = CodeBlockB::solve({a1, a2, a3, a4, a5, a6, a7, a8}, *this, ent);
    int result = 0;
    for (auto i: *pb) result += i;
    delete pb;
    return result;
}