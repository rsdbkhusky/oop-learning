//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENECHOSELEVEL_H
#define FINAL_SCENECHOSELEVEL_H

#include "Scene.h"

class SceneChoseLevel: public Scene {
public:
    SceneChoseLevel(Application* _mApplication, InputReceiver* _mInputReceiver, OutputDisplayer* _mOutputDisplayer):
    Scene(_mApplication, _mInputReceiver, _mOutputDisplayer) {
        // TODO: add mUIs
    }
};


#endif //FINAL_SCENECHOSELEVEL_H
