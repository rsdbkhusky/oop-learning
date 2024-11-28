//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM13_BOXTOXIN_H
#define PROBLEM13_BOXTOXIN_H


#include "Box.h"

class BoxToxin: public Box {
public:
    virtual void beOpenedBySolider(Solider& solider) override;
    virtual void beOpenedByMage(Mage& mage) override;
};

#endif //PROBLEM13_BOXTOXIN_H
