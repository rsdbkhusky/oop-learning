//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENE_H
#define FINAL_SCENE_H

#include <map>
#include <string>
using std::map;
using std::string;
class Application;
class InputReceiver;
class InputErrorHandler;
class OutputDisplayer;
class UI;
class IUI;
class InputMessage;

class Scene {
public:
    Scene(Application* _mApplication, InputReceiver* _mInputReceiver, InputErrorHandler* _mInputErrorHandler, OutputDisplayer* _mOutputDisplayer);
    virtual ~Scene() = default;
    void Update();
protected:
    static int durationOneUpdateInput;
    static string messageInputCantReceive;
    void solveOneUpdateInput();
    void solveOneInput(const string& input);
    void solveInputMessage(const InputMessage& inputMessage);
    Application* mApplication;
    InputReceiver* mInputReceiver;
    InputErrorHandler* mInputErrorHandler;
    OutputDisplayer* mOutputDisplayer;
    map<string, UI*> mUIs;
    IUI* mDisplayUIRoot;
    bool mReDisplay;
};

#endif //FINAL_SCENE_H
