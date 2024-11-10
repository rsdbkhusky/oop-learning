//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_SCENEGAME_H
#define FINAL_SCENEGAME_H

#include "Scene.h"

class LogicSudoku;

class SceneGame: public Scene {
public:
    SceneGame(Application* _mApplication, InputReceiver* _mInputReceiver, OutputDisplayer* _mOutputDisplayer):
    Scene(_mApplication, _mInputReceiver, _mOutputDisplayer) {
        // TODO: add mUIs
    }
private:
    LogicSudoku* mSudoku;
};


#endif //FINAL_SCENEGAME_H
