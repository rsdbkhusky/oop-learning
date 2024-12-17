//
// Created by lenovo on 2024/11/7.
//

#include "../../include/UI/UIButton.h"

UIButton::UIButton(const vector<vector<char>>& _mText, Scene* _mpScene, IUI* _mpFather): UI(_mpScene, _mpFather), mText(_mText) {}

const vector<vector<char>>& UIButton::getText() const {
    return mText;
}