//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM21_BANK_H
#define PROBLEM21_BANK_H

class CodeBlockB;
class Enterprise;

class Bank {
    friend class CodeBlockB;
public:
    Bank(int _prop1, int _prop2): prop1(_prop1), prop2(_prop2) {}
    int Evaluate(Enterprise& ent);
private:
    int BankFunc() const {
        return 10;
    }
    int prop1;
    int prop2;
};


#endif //PROBLEM21_BANK_H
