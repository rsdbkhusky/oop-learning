//
// Created by lenovo on 2024/11/7.
//

#include "../../include/Input/InputReceiver.h"

#include <iostream>
using std::cout;
using std::endl;

void InputReceiver::loadAllInput() {}

queue<string>* InputReceiver::operator->() {
    return &mInputList;
}
