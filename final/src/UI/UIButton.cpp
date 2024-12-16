//
// Created by lenovo on 2024/11/7.
//

#include "../../include/UI/UIButton.h"

UIButton::UIButton(const string& _mText): mText(_mText) {}

const string& UIButton::getText() const {
    return mText;
}