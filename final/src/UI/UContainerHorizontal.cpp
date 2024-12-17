//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UContainerHorizontal.h"

UContainerHorizontal::UContainerHorizontal(const vector<const IUI*>& _mIUIs, IUI* _mpFather): UContainer(_mpFather), mIUIs(_mIUIs) {}

const vector<const IUI*>& UContainerHorizontal::getIUIs() const {
    return mIUIs;
}