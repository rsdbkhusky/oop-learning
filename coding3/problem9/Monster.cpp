//
// Created by lenovo on 2024/11/27.
//

#include "Monster.h"

Monster::Monster(int _mHitpoint, int _mDamage, int _mDefense): mHitpoint(_mHitpoint), mDefense(_mDefense), mDamage(_mDamage) {}

int Monster::getHp() const {
    return mHitpoint;
}

void Monster::setHp(int hitpoint) {
    mHitpoint = hitpoint;
}

int Monster::getDf() const {
    return mDefense;
}

bool Monster::fight(Monster& enemy) {
    while (true) {
        this->attack(enemy);
        if (enemy.isAlive() == false) return true;
        enemy.attack(*this);
        if (this->isAlive() == false) return false;
    }
}

bool Monster::isAlive() {
    return mHitpoint > 0;
}
