//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_TURTLE_H
#define PROBLEM12_TURTLE_H


#include "Fish.h"

class Turtle: public Fish {
public:
    virtual ~Turtle() override = default;
    virtual int getExp(const Cat& cat) override;
};


#endif //PROBLEM12_TURTLE_H
