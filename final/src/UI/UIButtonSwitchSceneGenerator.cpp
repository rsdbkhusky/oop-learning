//
// Created by lenovo on 2024/12/18.
//

#include "../../include/UI/UIButtonSwitchSceneGenerator.h"
#include "../../include/Scene/SceGenerator.h"
#include "../../include/Scene/Scene.h"

UIButtonSwitchSceneGenerator::UIButtonSwitchSceneGenerator
    (SceGenerator* _mSceGenerator, const std::string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew,
     const vector<vector<char>>& _mText, Scene* _mpScene, IUI* _mpFather): mSceGenerator(_mSceGenerator),
     UIButtonSwitchScene(_mSwitchSceneName, _mDeleteCurrent, _mCreateNew, _mText, _mpScene, _mpFather) {}

Scene* UIButtonSwitchSceneGenerator::createNewScene(const InputMessage& inputMessage) {
    return mSceGenerator->genScene(&(mpScene->getApplication()));
}