//
// Created by lenovo on 2024/11/6.
//

#include <iostream>
#include "Parser.h"

int main() {
    uint16_t reg1 = 0x1234;
    uint16_t reg2 = 0x5678;
    int scale = 10;

    void* parser1 = createParser(reg1, reg2, 1, scale);
    int32_t result1 = parse(parser1);
    std::cout << "小端模式-整数解析结果：" << result1 << std::endl;
    destroyParser(parser1);

    void* parser2 = createParser(reg1, reg2, 2, scale);
    int32_t result2 = parse(parser2);
    std::cout << "大端模式-整数解析结果：" << result2 << std::endl;
    destroyParser(parser2);

    void* parser3 = createParser(reg1, reg2, 3, scale);
    float result3 = parse(parser3);
    std::cout << "小端模式-浮点数解析结果：" << result3 << std::endl;
    destroyParser(parser3);

    void* parser4 = createParser(reg1, reg2, 4, scale);
    float result4 = parse(parser4);
    std::cout << "大端模式-浮点数解析结果：" << result4 << std::endl;
    destroyParser(parser4);

    return 0;
}

/*
 * run> g++ -shared -DDLL_EXPORTS -o Parser.dll Parser.cpp -Wl,--out-implib,libParser.a
 * run> g++ main.cpp -o test_program.exe -L. -lParser
 */