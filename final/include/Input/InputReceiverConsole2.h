//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_INPUTRECEIVERCONSOLE2_H
#define FINAL_INPUTRECEIVERCONSOLE2_H


#include "../Utils/Singleton.h"
#include "InputReceiver.h"

class InputReceiverConsole2: public Singleton<InputReceiverConsole2>, public InputReceiver {
    friend class Singleton<InputReceiverConsole2>;
public:
    virtual void loadAllInput() override;
protected:
    InputReceiverConsole2() = default;
    virtual ~InputReceiverConsole2() override = default;
};


#endif //FINAL_INPUTRECEIVERCONSOLE2_H
