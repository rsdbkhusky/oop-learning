//
// Created by lenovo on 2024/11/7.
//

#include "../../include/Input/InputMessage.h"

const string& InputMessage::getName() const {
    return mName;
}

void InputMessage::setName(const string& name) {
    mName = name;
}

const vector<int>& InputMessage::getParas() const {
    return mParas;
}

void InputMessage::addPara(int para) {
    mParas.push_back(para);
}