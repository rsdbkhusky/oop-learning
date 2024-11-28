//
// Created by lenovo on 2024/11/28.
//

#include "BoxMoney.h"
#include "Solider.h"
#include "Mage.h"

BoxMoney::BoxMoney(int _mMoney): mMoney(_mMoney) {}

int BoxMoney::getMoney() const {
    return mMoney;
}

void BoxMoney::beOpenedBySolider(Solider& solider) {
    solider.setMoney(solider.getMoney() + mMoney);
    mMoney = 0;
}

void BoxMoney::beOpenedByMage(Mage& mage) {
    mage.setMoney(mage.getMoney() + mMoney);
    mMoney = 0;
}