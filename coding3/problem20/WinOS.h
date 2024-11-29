//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM20_WINOS_H
#define PROBLEM20_WINOS_H

#include "System.h"

class WinOS: public System {
public:
    virtual void playStandardVideoStream(const StandardVideoStream &standardVideoStream) override;
};


#endif //PROBLEM20_WINOS_H
