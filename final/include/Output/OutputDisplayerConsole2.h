//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_OUTPUTDISPLAYERCONSOLE2_H
#define FINAL_OUTPUTDISPLAYERCONSOLE2_H

#include "OutputDisplayer.h"

class OutputDisplayerConsole2: public Singleton<OutputDisplayerConsole2>, public OutputDisplayer {
    friend class Singleton<OutputDisplayerConsole2>;
public:
    virtual void displayAllUI(IUI &iui) override;
protected:
    OutputDisplayerConsole2() = default;
    virtual ~OutputDisplayerConsole2() override = default;
};


#endif //FINAL_OUTPUTDISPLAYERCONSOLE2_H
