//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_OCTOPUS_H
#define PROBLEM12_OCTOPUS_H


#include "Fish.h"

class Octopus: public Fish {
public:
    Octopus(int _mWeight);
    virtual ~Octopus() override = default;
    virtual int getExp(const Cat& cat) override;
protected:
    int mWeight;
};


#endif //PROBLEM12_OCTOPUS_H
