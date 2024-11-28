//
// Created by lenovo on 2024/11/28.
//

#include "Role.h"
#include "Box.h"

Role::Role(int _mHp, int _mMoney): mHp(_mHp), mMoney(_mMoney) {}

int Role::getHp() const {
    return mHp;
}

void Role::setHp(int hp) {
    mHp = hp;
}

int Role::getMoney() const {
    return mMoney;
}

void Role::setMoney(int money) {
    mMoney = money;
}

void Role::openBox(Box& box) {
    box.beOpened(*this);
}