//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM5_PARSER_H
#define PROBLEM5_PARSER_H

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
    API void* createParser(uint16_t reg1, uint16_t reg2, int mode, int scale);
    API void destroyParser(void* parser);
    API int32_t parse(void* parser);
}

#endif // PROBLEM5_PARSER_H
