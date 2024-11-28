//
// Created by lenovo on 2024/11/28.
//

#include "Manager.h"

Manager::Manager(long _mWage): Employee(_mWage) {}

long Manager::Award(long base) {
    return mWage * 2 + base * 2;
}