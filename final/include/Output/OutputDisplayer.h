//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_OUTPUTDISPLAYER_H
#define FINAL_OUTPUTDISPLAYER_H

#include "../Utils/Singleton.h"
#include "../UI/IUI.h"

class OutputDisplayer: public Singleton<OutputDisplayer> {
    friend class Singleton<OutputDisplayer>;
public:
    virtual void displayAllUI(IUI& iui);
protected:
    OutputDisplayer() = default;
    virtual ~OutputDisplayer() override = default;
};


#endif //FINAL_OUTPUTDISPLAYER_H
