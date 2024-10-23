//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM4_INPUT_H
#define PROBLEM4_INPUT_H

#include "KeyChar.h"
#include "Singleton.h"

class Input: public Singleton<Input> {
    friend class Singleton<Input>;
private:
    Input( ) = default;
public:
    unsigned long getRangeULong( unsigned long min, unsigned long max );
    KeyChar::Value getKeyChar( unsigned long flags, bool caseSensitive = false );
};

#endif //PROBLEM4_INPUT_H
