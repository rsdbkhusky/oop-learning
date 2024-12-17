//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerVertical.h"

UContainerVertical::UContainerVertical(const vector<const IUI*>& _mIUIs, IUI* _mpFather): UContainer(_mpFather), mIUIs(_mIUIs) {}

const vector<const IUI*>& UContainerVertical::getIUIs() const {
    return mIUIs;
}