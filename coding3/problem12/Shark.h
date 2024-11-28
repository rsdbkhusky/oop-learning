//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_SHARK_H
#define PROBLEM12_SHARK_H


#include "Fish.h"

class Shark: public Fish {
public:
    Shark(int _mWeight);
    virtual ~Shark() override = default;
    virtual int getExp(const Cat& cat) override;
protected:
    int mWeight;
};


#endif //PROBLEM12_SHARK_H
