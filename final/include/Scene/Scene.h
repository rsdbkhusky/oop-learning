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
//    Scene(Application* _mApplication, InputReceiver* _mInputReceiver, InputErrorHandler* _mInputErrorHandler, OutputDisplayer* _mOutputDisplayer);
    Scene(Application* _mpApplication, bool _mReDisplay = true);
    void setUIs(const map<string, UI*>& _mUIs);
    void setUIRoot(IUI* _mpUIRoot);
    Scene(Application* _mpApplication, const map<string, UI*>& _mUIs, IUI* _mpUIRoot, bool _mReDisplay = true);
    Scene(const Scene& rhs) = delete;
    Scene& operator=(const Scene& rhs) = delete;
    virtual ~Scene();
    Application& getApplication();
    void setReDisplay(bool reDisplay);
    void autoUpdate();
    void temp_autoUpdate1();
    void temp_autoUpdate2();
protected:
    static int durationOneUpdateInput;
    static string messageInputCantReceive;
    static void dfsDelete(IUI* cur);
    void solveOneUpdateInput();
    void solveOneInput(const string& input);
    void solveInputMessage(const InputMessage& inputMessage);
    virtual void customUpdate();
    Application* mpApplication;
//    InputReceiver* mInputReceiver;
//    InputErrorHandler* mInputErrorHandler;
//    OutputDisplayer* mOutputDisplayer; // 这三行预计要删掉
    map<string, UI*> mUIs;
    IUI* mpUIRoot;
    bool mReDisplay;
};

#endif //FINAL_SCENE_H
