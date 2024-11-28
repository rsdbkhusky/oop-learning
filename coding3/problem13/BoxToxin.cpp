//
// Created by lenovo on 2024/11/28.
//

#include "BoxToxin.h"
#include "Solider.h"
#include "Mage.h"

void BoxToxin::beOpenedBySolider(Solider& solider) {
    solider.setMoney(solider.getMoney() * 1.2);
    solider.setHp(solider.getHp() * 0.9);
}

void BoxToxin::beOpenedByMage(Mage& mage) {
    mage.setMoney(mage.getMoney() * 1.4);
    mage.setHp(mage.getHp() * 0.7);
}