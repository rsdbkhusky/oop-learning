//
// Created by lenovo on 2024/11/6.
//

#include "ushort_to_float32.h"

float ushortToFloat32(uint16_t high, uint16_t low) {
    uint32_t combined = (static_cast<uint32_t>(high) << 16) | low;
    float result = *reinterpret_cast<float*>(&combined);
    result = static_cast<int>(result * 100 + 0.5) / 100.0f;
    return result;
}
