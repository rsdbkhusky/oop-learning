//
// Created by lenovo on 2024/11/28.
//

#include "Stuff.h"

Stuff::Stuff(long _mWage): Employee(_mWage) {}

long Stuff::Award(long base) {
    return mWage + base * 0.8;
}