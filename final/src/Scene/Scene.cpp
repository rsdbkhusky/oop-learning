//
// Created by lenovo on 2024/11/7.
//

#include <thread>
#include "../../include/Scene/Scene.h"
#include "../../include/Input/InputReceiver.h"
#include "../../include/Input/InputProcessor.h"
#include "../../include/Input/InputErrorHandler.h"
#include "../../include/UI/UI.h"
#include "../../include/Output/OutputDisplayer.h"
#include "../../include/UI/UContainer.h"
#include "../../include/Application/Application.h"

#include <iostream>
using std::cout;
using std::endl;

//Scene::Scene(Application* _mApplication, InputReceiver* _mInputReceiver, InputErrorHandler* _mInputErrorHandler, OutputDisplayer* _mOutputDisplayer):
//mpApplication(_mApplication), mInputReceiver(_mInputReceiver), mInputErrorHandler(_mInputErrorHandler), mOutputDisplayer(_mOutputDisplayer), mReDisplay(true) {}

Scene::Scene(Application* _mpApplication, bool _mReDisplay): mpApplication(_mpApplication), mReDisplay(_mReDisplay) {}

void Scene::setUIs(const map<std::string, UI*>& _mUIs) {
    mUIs = _mUIs;
}

void Scene::setUIRoot(IUI* _mpUIRoot) {
    mpUIRoot = _mpUIRoot;
}

Scene::Scene(Application* _mpApplication, const map<string, UI*>& _mUIs, IUI* _mpUIRoot, bool _mReDisplay):
        mpApplication(_mpApplication), mUIs(_mUIs), mpUIRoot(_mpUIRoot), mReDisplay(_mReDisplay) {}

void Scene::dfsDelete(IUI* cur) {
    if (dynamic_cast<UContainer*>(cur) != nullptr) {
        UContainer* curr = dynamic_cast<UContainer*>(cur);
        for (auto& i: *curr) {
            dfsDelete(i);
        }
    }
    delete cur;
}

Scene::~Scene() {
    dfsDelete(mpUIRoot);
}

void Scene::setReDisplay(bool reDisplay) {
    mReDisplay = reDisplay;
}

Application& Scene::getApplication() {
    return *mpApplication;
}

int Scene::durationOneUpdateInput = 20;

string Scene::messageInputCantReceive = "格式错误";

void Scene::solveOneUpdateInput() {
//    cout << "start solveOneUpdateInput" << endl;
    InputReceiver* inputReceiver = mpApplication->getInputReceiver();
    auto start = std::chrono::steady_clock::now();
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
        if (elapsed.count() > durationOneUpdateInput) break;
        if (!(*inputReceiver)->empty()) {
            solveOneInput((*inputReceiver)->front());
            (*inputReceiver)->pop();
        }
    }
//    cout << "end solveOneUpdateInput" << endl;
}

void Scene::solveOneInput(const std::string& input) {
//    cout << "solveOneInput: " << input << endl;
    auto [inputReturnValue, inputMessage] = InputProcessor::string2message(input);
    if (inputReturnValue == InputReturnValue::SUCCESS) {
        solveInputMessage(inputMessage);
    } else {
        mpApplication->getInputErrorHandler()->setMessage(Scene::messageInputCantReceive);
    }
}

void Scene::solveInputMessage(const InputMessage& inputMessage) {
//    cout << "solveInputMessage: " << inputMessage.getName() << ": ";
//    for (auto i: inputMessage.getParas()) cout << i << " ";
//    cout << endl;
    UI& ui = *mUIs[inputMessage.getName()];
    ui.receive(inputMessage);
}

void Scene::customUpdate() {}

void Scene::autoUpdate() {
    mpApplication->getInputReceiver()->loadAllInput();
    solveOneUpdateInput();
    customUpdate();
    if (mReDisplay) {
        mReDisplay = false;
        IUI* handleDisplayUIRoot = mpApplication->getInputErrorHandler()->handleDisplayUIRoot(mpUIRoot);
        mpApplication->getOutputDisplayer()->displayAllUI(*handleDisplayUIRoot);
        delete handleDisplayUIRoot;
    }
    mpApplication->getInputErrorHandler()->resetMessage(); // TODO: InputErrorHandler未测试
}

void Scene::temp_autoUpdate1() {
    mpApplication->getInputReceiver()->loadAllInput();
    solveOneUpdateInput();
    customUpdate();
}

void Scene::temp_autoUpdate2() {
    if (mReDisplay) {
        mReDisplay = false;
        IUI* handleDisplayUIRoot = mpApplication->getInputErrorHandler()->handleDisplayUIRoot(mpUIRoot);
        mpApplication->getOutputDisplayer()->displayAllUI(*handleDisplayUIRoot);
        delete handleDisplayUIRoot;
    }
    mpApplication->getInputErrorHandler()->resetMessage(); // TODO: InputErrorHandler未测试
}