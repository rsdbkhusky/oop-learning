//
// Created by lenovo on 2024/11/6.
//

#include "Utility.h"

int Utility::countBits0(int x) {
    int numBits0 = 0;
    for (int i = 0; i < 32; ++i) {
        numBits0 += !(x & 1);
        x >>= 1;
    }
    return numBits0;
}

int Utility::countBits1(int x) {
    return 32 - Utility::countBits0(x);
}