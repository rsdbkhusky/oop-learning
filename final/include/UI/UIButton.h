//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_UIBUTTON_H
#define FINAL_UIBUTTON_H

#include <string>
#include "UI.h"
using std::string;

class UIButton: public UI {
public:
    UIButton(const string& _mText);
    const string& getText() const;
protected:
    string mText;
};


#endif //FINAL_UIBUTTON_H
