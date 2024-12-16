//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_OUTPUTDISPLAYERCONSOLE_H
#define FINAL_OUTPUTDISPLAYERCONSOLE_H

#include "OutputDisplayer.h"

class OutputDisplayerConsole: public Singleton<OutputDisplayerConsole>, public OutputDisplayer {
    friend class Singleton<OutputDisplayerConsole>;
public:
    virtual void displayAllUI(IUI &iui) override;
protected:
    OutputDisplayerConsole() = default;
    virtual ~OutputDisplayerConsole() override = default;
};


#endif //FINAL_OUTPUTDISPLAYERCONSOLE_H
