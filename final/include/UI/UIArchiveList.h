//
// Created by lenovo on 2024/12/17.
//

#ifndef FINAL_UIARCHIVELIST_H
#define FINAL_UIARCHIVELIST_H

#include "UIButtonSwitchScene.h"

class UIArchiveList: public UIButtonSwitchScene {
public:
    UIArchiveList(const string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew,
                  Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    virtual ~UIArchiveList() override = default;
    virtual Scene* createNewScene(const InputMessage &inputMessage) override;
    static vector<char> string2vc(const string& str);
    static vector<char> vcFillGivenLength(const vector<char>& vc, int length, char ch = ' ');
};


#endif //FINAL_UIARCHIVELIST_H
