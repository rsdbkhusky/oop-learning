//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/IUI.h"

IUI::IUI(IUI* _mpFather): mpFather(_mpFather) {}

IUI* IUI::getFather() {
    return mpFather;
}

void IUI::setFather(IUI* iui) {
    mpFather = iui;
}