//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM9_DOG_H
#define PROBLEM9_DOG_H


#include "Monster.h"

class Dog: public Monster {
public:
    Dog(int _mHitpoint = 0, int _mDamage = 0, int _mDefense = 0);
    virtual void attack(Monster &enemy) override;
};


#endif //PROBLEM9_DOG_H
