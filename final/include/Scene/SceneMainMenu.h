//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENEMAINMENU_H
#define FINAL_SCENEMAINMENU_H

#include "Scene.h"

class SceneMainMenu: public Scene {
public:
    SceneMainMenu(Application* _mApplication, InputReceiver* _mInputReceiver, OutputDisplayer* _mOutputDisplayer):
    Scene(_mApplication, _mInputReceiver, _mOutputDisplayer) {
        // TODO: add mUIs
    }
};


#endif //FINAL_SCENEMAINMENU_H
