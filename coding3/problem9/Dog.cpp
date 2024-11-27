//
// Created by lenovo on 2024/11/27.
//

#include <algorithm>
#include "Dog.h"
using std::max;

Dog::Dog(int _mHitpoint, int _mDamage, int _mDefense): Monster(_mHitpoint, _mDamage, _mDefense) {}

void Dog::attack(Monster& enemy) {
    int enemyHp = enemy.getHp();
    int enemyDf = enemy.getDf();
    enemyHp -= max(2, (mDamage - enemyDf + 5) * 2);
    enemy.setHp(enemyHp);
}
