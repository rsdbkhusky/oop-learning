//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_UITEXT_H
#define FINAL_UITEXT_H

#include <string>
#include "UI.h"
using std::string;

class UIText: public UI {
public:
    UIText(const string& _mText, Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    const string& getText() const;
protected:
    string mText;
};


#endif //FINAL_UITEXT_H
