//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_UIBUTTONSWITCHSCENEGENERATOR_H
#define FINAL_UIBUTTONSWITCHSCENEGENERATOR_H

#include "UIButtonSwitchScene.h"
class SceGenerator;

class UIButtonSwitchSceneGenerator: public UIButtonSwitchScene {
public:
    UIButtonSwitchSceneGenerator(SceGenerator* _mSceGenerator, const string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew,
                        const vector<vector<char>>& _mText, Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    virtual ~UIButtonSwitchSceneGenerator() override = default;
    virtual Scene * createNewScene(const InputMessage &inputMessage) override;
protected:
    SceGenerator* mSceGenerator;
};


#endif //FINAL_UIBUTTONSWITCHSCENEGENERATOR_H
