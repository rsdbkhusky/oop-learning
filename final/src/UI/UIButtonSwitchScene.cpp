//
// Created by lenovo on 2024/12/17.
//

#include <cassert>
#include "../../include/UI/UIButtonSwitchScene.h"
#include "../../include/Scene/Scene.h"
#include "../../include/Application/Application.h"

UIButtonSwitchScene::UIButtonSwitchScene(const string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew,
                                         const vector<vector<char>>& _mText, Scene* _mpScene, IUI* _mpFather):
        mSwitchSceneName(_mSwitchSceneName), mDeleteCurrent(_mDeleteCurrent), mCreateNew(_mCreateNew),
        UIButton(_mText, _mpScene, _mpFather) {}

Scene* UIButtonSwitchScene::createNewScene(const InputMessage& inputMessage) {
    assert(!"This Class Can't createNewScene!");
    return nullptr;
}

void UIButtonSwitchScene::receive(const InputMessage& inputMessage) {
    mpScene->setReDisplay(true);
    Application& application = mpScene->getApplication();
    if (mDeleteCurrent) {
        application.addWatingList({AppWatingList::DELETESCENE, application.getRunningSceneName(), nullptr});
    }
    if (mCreateNew) {
        application.addWatingList({AppWatingList::CREATESCENE, mSwitchSceneName, createNewScene(inputMessage)});
    }
    application.addWatingList({AppWatingList::SWITCHSCENE, mSwitchSceneName, nullptr});
}