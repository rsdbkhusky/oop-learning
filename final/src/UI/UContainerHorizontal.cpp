//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerHorizontal.h"

UContainerHorizontal::UContainerHorizontal(const vector<IUI*>& _mIUIs): mIUIs(_mIUIs) {}

const vector<IUI*>& UContainerHorizontal::getIUIs() const {
    return mIUIs;
}