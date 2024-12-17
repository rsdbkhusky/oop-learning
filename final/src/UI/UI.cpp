//
// Created by lenovo on 2024/11/7.
//

#include "../../include/UI/UI.h"

UI::UI(Scene* _mpScene, IUI* _mpFather): IUI(_mpFather), mpScene(_mpScene) {}

void UI::receive(const InputMessage& inputMessage) {}