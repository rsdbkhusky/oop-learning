//
// Created by lenovo on 2024/11/7.
//

#include "../../include/Application/Application.h"
#include "../../include/Scene/Scene.h"

Application::Application(InputReceiver* _mpInputReceiver, InputErrorHandler* _mpInputErrorHandler,
                         OutputDisplayer* _mpOutputDisplayer, DataManager* _mpDataManager):
                         mpInputReceiver(_mpInputReceiver), mpInputErrorHandler(_mpInputErrorHandler),
                         mpOutputDisplayer(_mpOutputDisplayer), mpDataManager(_mpDataManager) {}

void Application::setScenes(const map<std::string, Scene*>& _mScenes) {
    mScenes = _mScenes;
}

void Application::setRunningSceneName(const std::string& _mRunningSceneName) {
    mRunningSceneName = _mRunningSceneName;
}

Application::Application(InputReceiver* _mpInputReceiver, InputErrorHandler* _mpInputErrorHandler,
                         OutputDisplayer* _mpOutputDisplayer, DataManager* _mpDataManager,
                         const map<string, Scene*>& _mScenes, const string& _mRunningSceneName):
                         mpInputReceiver(_mpInputReceiver), mpInputErrorHandler(_mpInputErrorHandler),
                         mpOutputDisplayer(_mpOutputDisplayer), mpDataManager(_mpDataManager),
                         mScenes(_mScenes), mRunningSceneName(_mRunningSceneName) {}

Application::~Application() {
    for (auto& i: mScenes) {
        delete i.second;
    }
    while (!mWatingList.empty()) {
        auto& i = mWatingList.front();
        delete get<2>(i);
        mWatingList.pop();
    }
}

const map<string, Scene*>& Application::getScenes() const {
    return mScenes;
}

const string& Application::getRunningSceneName() const {
    return mRunningSceneName;
}

InputReceiver* Application::getInputReceiver() {
    return mpInputReceiver;
}

InputErrorHandler* Application::getInputErrorHandler() {
    return mpInputErrorHandler;
}

OutputDisplayer* Application::getOutputDisplayer() {
    return mpOutputDisplayer;
}

DataManager* Application::getDataManager() {
    return mpDataManager;
}

void Application::addWatingList(const tuple<AppWatingList, string, Scene*>& tp) {
    mWatingList.push(tp);
}

void Application::deleteScene(const string& sceneName) {
    delete mScenes[sceneName];
    mScenes[sceneName] = nullptr;
}

void Application::createScene(const string& sceneName, Scene* scene) {
    if (mScenes[sceneName] != nullptr) deleteScene(sceneName);
    mScenes[sceneName] = scene;
}

void Application::switchScene(const string& sceneName) {
    mRunningSceneName = sceneName;
}

void Application::solveWatingList() {
    while (!mWatingList.empty()) {
        const tuple<AppWatingList, string, Scene*>& tp = mWatingList.front();
        if (get<0>(tp) == AppWatingList::DELETESCENE) {
            deleteScene(get<1>(tp));
        } else if (get<0>(tp) == AppWatingList::CREATESCENE) {
            createScene(get<1>(tp), get<2>(tp));
        } else if (get<0>(tp) == AppWatingList::SWITCHSCENE) {
            switchScene(get<1>(tp));
        }
        mWatingList.pop();
    }
}

void Application::run() {
    while (true) {
        mScenes[mRunningSceneName]->autoUpdate();
        solveWatingList();
    }
}

void Application::temp_run2() {
    while (true) {
        mScenes[mRunningSceneName]->temp_autoUpdate1();
        solveWatingList();
        mScenes[mRunningSceneName]->temp_autoUpdate2();
    }
}