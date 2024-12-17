//
// Created by lenovo on 2024/12/16.
//

#include "../../include/UI/UIText.h"

UIText::UIText(const string& _mText): mText(_mText) {}

const string& UIText::getText() const {
    return mText;
}