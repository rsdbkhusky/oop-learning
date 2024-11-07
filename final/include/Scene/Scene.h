//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENE_H
#define FINAL_SCENE_H

#include <vector>
using std::vector;
class Application;
class InputReceiver;
class OutputDisplayer;
class UI;

class Scene {
private:
    Application *mApplication;
    InputReceiver* mInputReveiver;
    OutputDisplayer* mOutputDisplayer;
    vector<UI*> mUIs;
};

#endif //FINAL_SCENE_H
