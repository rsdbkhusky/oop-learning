//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_INPUTRECEIVER_H
#define FINAL_INPUTRECEIVER_H

#include <queue>
#include <string>
#include "../Utils/Singleton.h"
using std::queue;
using std::string;

class InputReceiver: public Singleton<InputReceiver> {
    friend class Singleton<InputReceiver>;
public:
    queue<string>* operator->();
    virtual void loadAllInput();
protected:
    InputReceiver() = default;
    virtual ~InputReceiver() override = default;
    queue<string> mInputList;
};

#endif //FINAL_INPUTRECEIVER_H
