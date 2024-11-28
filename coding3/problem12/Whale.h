//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_WHALE_H
#define PROBLEM12_WHALE_H


#include "Fish.h"

class Whale: public Fish {
public:
    virtual ~Whale() override = default;
    virtual int getExp(const Cat& cat) override;
};


#endif //PROBLEM12_WHALE_H
