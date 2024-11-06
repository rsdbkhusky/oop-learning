//
// Created by lenovo on 2024/11/6.
//

#include <cstdint>
#include <iostream>

float ushortToFloat32(uint16_t high, uint16_t low) {
    uint32_t combined = (static_cast<uint32_t>(high) << 16) | low;
    float result = *reinterpret_cast<float*>(&combined);
    result = static_cast<int>(result * 100 + 0.5) / 100.0f;
    return result;
}

int main() {
    uint16_t high1 = 16243;
    uint16_t low1 = 62432;
    float result1 = ushortToFloat32(high1, low1);
    std::cout << "ushortToFloat32��16243,62432���ķ���ֵΪ��" << result1 << std::endl;

    uint16_t high2 = 17470;
    uint16_t low2 = 52429;
    float result2 = ushortToFloat32(high2, low2);
    std::cout << "ushortToFloat32��17470,52429���ķ���ֵΪ��" << result2 << std::endl;
    return 0;
}