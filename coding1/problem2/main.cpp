//
// Created by lenovo on 2024/10/22.
//

#include <iostream>
#include <string>
using namespace std;

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Gender.h"

int main() {
    setlocale( LC_ALL, ".UTF-8" ); //设置运行环境的编码为utf-8
#ifdef _WIN32
    SetConsoleOutputCP( CP_UTF8 ); //设置Windows的控制台输出编码为utf-8
#endif
    Gender & 张 = Gender::MALE;
    Gender & 王 = Gender::FEMALE;
    Gender & 杨 = Gender::FEMALE;
    if ( 王 == 杨 ) {
        cout << u8"小王和小杨，性别相同，性别都为" << 王.toString( Lang::CHN ) << endl;
    } else {
        cout << u8"小王和小杨，性别不同."<< endl;
    }
    if ( 张 != 王 ) {
        cout << u8"小张和小王，性别不同." << endl;
    } else {
        cout << u8"小张和小王，性别相同，性别都为" << 王.toString( Lang::CHN ) << endl;
    }
    cout << "===========" << endl;
    cout << u8"张 = " << 张.toString( Lang::CHN ) << endl;
    cout << u8"王 = " << 王.toString( Lang::CHN ) << endl << endl;
    cout << u8"张 = " << 张.toString( Lang::ENG ) << endl;
    cout << u8"王 = " << 王.toString( Lang::ENG ) << endl << endl;
    cout << u8"张 = " << 张.toString( Lang::FRA ) << endl;
    cout << u8"王 = " << 王.toString( Lang::FRA ) << endl << endl;
    cout << u8"张 = " << 张.toString( Lang::GER ) << endl;
    cout << u8"王 = " << 王.toString( Lang::GER ) << endl << endl;
    cout << u8"吉林大学" << endl;
    system( "pause" );
}
