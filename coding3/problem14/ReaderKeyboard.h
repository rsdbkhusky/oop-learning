//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM14_READERKEYBOARD_H
#define PROBLEM14_READERKEYBOARD_H

#include "Reader.h"

class ReaderKeyboard: public Reader {
public:
    virtual char read() override;
};


#endif //PROBLEM14_READERKEYBOARD_H
