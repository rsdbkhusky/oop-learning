//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UIText.h"

UIText::UIText(const string& _mText, Scene* _mpScene, IUI* _mpFather): mText(_mText), UI(_mpScene, _mpFather) {}

const string& UIText::getText() const {
    return mText;
}