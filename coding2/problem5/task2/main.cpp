//
// Created by lenovo on 2024/11/6.
//

#include <iostream>
#include "ushort_to_float32.h"

int main() {
    uint16_t high1 = 16243;
    uint16_t low1 = 62432;
    float result1 = ushortToFloat32(high1, low1);
    std::cout << "ushortToFloat32（16243,62432）的返回值为：" << result1 << std::endl;

    uint16_t high2 = 17470;
    uint16_t low2 = 52429;
    float result2 = ushortToFloat32(high2, low2);
    std::cout << "ushortToFloat32（17470,52429）的返回值为：" << result2 << std::endl;

    return 0;
}

/*
 * run> g++ -f PIC -shared ushort_to_float32.cpp -o libushort_to_float32.so
 * run> g++ main.cpp -L. -lushort_to_float32 -o test_program
 */