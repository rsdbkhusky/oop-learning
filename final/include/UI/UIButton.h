//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_UIBUTTON_H
#define FINAL_UIBUTTON_H

#include <vector>
#include "UI.h"
using std::vector;

class UIButton: public UI {
public:
    UIButton(const vector<vector<char>>& _mText, Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    virtual ~UIButton() override = default;
    const vector<vector<char>>& getText() const;
protected:
    vector<vector<char>> mText;
};


#endif //FINAL_UIBUTTON_H
