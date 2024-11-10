//
// Created by lenovo on 2024/11/7.
//

#include <conio.h>
#include "../../include/Input/InputReceiverConsole.h"

#include <iostream>
using std::cout;
using std::endl;

void InputReceiverConsole::loadAllInput() {
//    cout << "start loadAllInput" << endl;
    static string inputStr;
    while (_kbhit()) {
        char ch = _getch();
        if (ch == '\r') {
            if (!inputStr.empty()) {
                mInputList.push(inputStr);
                inputStr.clear();
            }
        } else {
            inputStr += ch;
        }
    }
//    cout << "end loadAllInput" << endl;
}