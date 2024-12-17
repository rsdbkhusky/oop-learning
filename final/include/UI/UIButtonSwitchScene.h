//
// Created by lenovo on 2024/12/17.
//

#ifndef FINAL_UIBUTTONSWITCHSCENE_H
#define FINAL_UIBUTTONSWITCHSCENE_H

#include <string>
#include "UIButton.h"
using std::string;

class UIButtonSwitchScene: public UIButton {
public:
    UIButtonSwitchScene(const string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew,
                        const vector<vector<char>>& _mText, Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    virtual ~UIButtonSwitchScene() override = default;
    virtual Scene* createNewScene(const InputMessage& inputMessage);
    virtual void receive(const InputMessage &inputMessage) override;
protected:
    bool mDeleteCurrent;
    bool mCreateNew;
    string mSwitchSceneName;
};


#endif //FINAL_UIBUTTONSWITCHSCENE_H
