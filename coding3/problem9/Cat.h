//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM9_CAT_H
#define PROBLEM9_CAT_H


#include "Monster.h"

class Cat: public Monster {
public:
    Cat(int _mHitpoint = 0, int _mDamage = 0, int _mDefense = 0);
    virtual void attack(Monster &enemy) override;
};


#endif //PROBLEM9_CAT_H
