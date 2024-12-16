//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerVertical.h"

UContainerVertical::UContainerVertical(const vector<IUI*>& _mIUIs): mIUIs(_mIUIs) {}

const vector<IUI*>& UContainerVertical::getIUIs() const {
    return mIUIs;
}