//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_INPUTRECEIVERCONSOLE_H
#define FINAL_INPUTRECEIVERCONSOLE_H


#include "../Utils/Singleton.h"
#include "InputReceiver.h"

class InputReceiverConsole: public Singleton<InputReceiverConsole>, public InputReceiver {
    friend class Singleton<InputReceiverConsole>;
public:
    virtual void loadAllInput() override;
protected:
    InputReceiverConsole() = default;
    virtual ~InputReceiverConsole() override = default;
};


#endif //FINAL_INPUTRECEIVERCONSOLE_H
