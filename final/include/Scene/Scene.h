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
class OutputDisplayer;
class UI;
class InputMessage;

class Scene {
public:
    Scene(Application* _mApplication, InputReceiver* _mInputReceiver, OutputDisplayer* _mOutputDisplayer);
    virtual ~Scene() = default;
    void Update();
protected:
    static int durationOneUpdateInput;
    void solveOneUpdateInput();
    void solveOneInput(const string& input);
    void solveInputMessage(const InputMessage& inputMessage);
    Application* mApplication;
    InputReceiver* mInputReceiver;
    OutputDisplayer* mOutputDisplayer;
    map<string, UI*> mUIs;
};

#endif //FINAL_SCENE_H
