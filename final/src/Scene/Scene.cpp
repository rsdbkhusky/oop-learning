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

#include <iostream>
using std::cout;
using std::endl;

Scene::Scene(Application* _mApplication, InputReceiver* _mInputReceiver, InputErrorHandler* _mInputErrorHandler, OutputDisplayer* _mOutputDisplayer):
mApplication(_mApplication), mInputReceiver(_mInputReceiver), mInputErrorHandler(_mInputErrorHandler), mOutputDisplayer(_mOutputDisplayer), mReDisplay(true) {}

int Scene::durationOneUpdateInput = 1000;

string Scene::messageInputCantReceive = "格式错误";

void Scene::solveOneUpdateInput() {
//    cout << "start solveOneUpdateInput" << endl;
    auto start = std::chrono::steady_clock::now();
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
        if (elapsed.count() > durationOneUpdateInput) break;
        if (!(*mInputReceiver)->empty()) {
            solveOneInput((*mInputReceiver)->front());
            (*mInputReceiver)->pop();
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
        mInputErrorHandler->setMessage(Scene::messageInputCantReceive);
    }
}

void Scene::solveInputMessage(const InputMessage& inputMessage) {
//    cout << "solveInputMessage: " << inputMessage.getName() << ": ";
    for (auto i: inputMessage.getParas()) cout << i << " ";
    cout << endl;
    const UI& ui = *mUIs[inputMessage.getName()];
    // TODO: ui.receive
}

void Scene::Update() {
    while (true) {
//        cout << "############## Update ##############" << endl;
        mInputReceiver->loadAllInput();
        solveOneUpdateInput();
        if (mReDisplay) {
            mReDisplay = false;
            IUI* handleDisplayUIRoot = mInputErrorHandler->handleDisplayUIRoot(mDisplayUIRoot);
            mOutputDisplayer->displayAllUI(*handleDisplayUIRoot);
            delete handleDisplayUIRoot;
        }
        mInputErrorHandler->resetMessage(); // TODO: InputErrorHandler未测试
//        func2();
    }
}