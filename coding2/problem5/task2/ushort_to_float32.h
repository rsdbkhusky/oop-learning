//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM5_USHORT_TO_FLOAT32_H
#define PROBLEM5_USHORT_TO_FLOAT32_H

#include <cstdint>

#ifdef _WIN32
#ifdef DLL_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif
#else
#define API
#endif

extern "C" {
API float ushortToFloat32(uint16_t high, uint16_t low);
}

#endif //PROBLEM5_USHORT_TO_FLOAT32_H
