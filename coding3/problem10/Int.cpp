//
// Created by lenovo on 2024/11/27.
//

#include "Int.h"

Int::Int(int _mInt): mInt(_mInt) {}

int Int::getInt() const {
    return mInt;
}

void Int::transform() {
    mInt = mInt * mInt;
}