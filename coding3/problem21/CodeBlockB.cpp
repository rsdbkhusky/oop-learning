//
// Created by lenovo on 2024/11/29.
//

#include "CodeBlockB.h"
#include "Bank.h"
#include "Enterprise.h"

vector<int>* CodeBlockB::solve(const vector<int>& a, Bank& bank, const Enterprise& ent) {
    int b1 = ent.EntFunc() + a[3];
    int b2 = a[0] * bank.BankFunc();
    int b3 = 10;
    int b4 = 0;
    int b5 = 10;
    int b6 = 0;
    int b7 = 0;
    int b8 = 0;
    int b9 = b3 - b5 * bank.prop2;
    return new vector({b1, b2, b3, b4, b5, b6, b7, b8, b9});
}