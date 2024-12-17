//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerVertical.h"

UContainerVertical::UContainerVertical(const vector<IUI*>& _mIUIs, IUI* _mpFather): UContainer(_mpFather), mIUIs(_mIUIs) {}

IUI** UContainerVertical::begin() {
    return mIUIs.data();
}

IUI** UContainerVertical::end() {
    return mIUIs.data() + mIUIs.size();
}

const vector<IUI*>& UContainerVertical::getIUIs() const {
    return mIUIs;
}