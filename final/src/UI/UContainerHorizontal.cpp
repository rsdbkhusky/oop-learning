//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerHorizontal.h"

UContainerHorizontal::UContainerHorizontal(const vector<IUI*>& _mIUIs, IUI* _mpFather): UContainer(_mpFather), mIUIs(_mIUIs) {}

IUI** UContainerHorizontal::begin() {
    return mIUIs.data();
}

IUI** UContainerHorizontal::end() {
    return mIUIs.data() + mIUIs.size();
}

const vector<IUI*>& UContainerHorizontal::getIUIs() const {
    return mIUIs;
}