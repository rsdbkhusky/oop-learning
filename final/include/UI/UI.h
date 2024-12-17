//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_UI_H
#define FINAL_UI_H

#include "IUI.h"
class InputMessage;
class Scene;

class UI: public IUI {
public:
    UI(Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    virtual ~UI() override = default;
    virtual void receive(const InputMessage& inputMessage);
protected:
    Scene* mpScene;
};


#endif //FINAL_UI_H
