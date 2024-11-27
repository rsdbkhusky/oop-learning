//
// Created by lenovo on 2024/11/27.
//

#include <algorithm>
#include "Cat.h"
using std::max;

Cat::Cat(int _mHitpoint, int _mDamage, int _mDefense): Monster(_mHitpoint, _mDamage, _mDefense) {}

void Cat::attack(Monster& enemy) {
    int enemyHp = enemy.getHp();
    int enemyDf = enemy.getDf();
    enemyHp -= max(1, mDamage * 2 - enemyDf);
    enemy.setHp(enemyHp);
}
