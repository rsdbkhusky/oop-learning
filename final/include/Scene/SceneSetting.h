//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENESETTING_H
#define FINAL_SCENESETTING_H

#include "Scene.h"

class SceneSetting: public Scene {
public:
    SceneSetting(Application* _mApplication, InputReceiver* _mInputReceiver, OutputDisplayer* _mOutputDisplayer):
    Scene(_mApplication, _mInputReceiver, _mOutputDisplayer) {
        // TODO: add mUIs
    }
};


#endif //FINAL_SCENESETTING_H
