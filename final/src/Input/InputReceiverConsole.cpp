//
// Created by lenovo on 2024/12/18.
//

#include <conio.h>
#include "../../include/Input/InputReceiverConsole.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void InputReceiverConsole::loadAllInput() {
//    static string inputStr;
//    while (_kbhit()) {
//        char ch = _getch();
//        if (ch == '\r') {
//            if (!inputStr.empty()) {
//                mInputList.push(inputStr);
//                inputStr.clear();
//            }
//        } else {
//            inputStr += ch;
//        }
//    }
    string temp;
    getline(cin, temp);
    if (!temp.empty()) mInputList.push(temp);
}