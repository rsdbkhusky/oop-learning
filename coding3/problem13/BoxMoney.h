//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM13_BOXMONEY_H
#define PROBLEM13_BOXMONEY_H

#include "Box.h"

class BoxMoney: public Box {
public:
    BoxMoney(int _mMoney);
    int getMoney() const;
    virtual void beOpenedBySolider(Solider& solider) override;
    virtual void beOpenedByMage(Mage& mage) override;
private:
    int mMoney;
};


#endif //PROBLEM13_BOXMONEY_H
