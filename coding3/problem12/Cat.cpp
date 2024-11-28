//
// Created by lenovo on 2024/11/28.
//

#include <cmath>
#include "Cat.h"
#include "Fish.h"
using std::floor;

int Cat::getOneLevelExp() {
    return 500;
}

Cat::Cat(int _mLevel, int _mExp): mLevel(_mLevel), mExp(_mExp) {}

int Cat::getLevel() const {
    return mLevel;
}

int Cat::getExp() const {
    return mExp;
}

void Cat::addExpAndLevel(int exp) {
    mExp += exp;
    mLevel += floor( (double)mExp / Cat::getOneLevelExp() );
    mExp = ((mExp % Cat::getOneLevelExp()) + Cat::getOneLevelExp()) % Cat::getOneLevelExp();
}

void Cat::CatchFish(Fish& fish) {
    int exp = fish.getExp(*this);
    addExpAndLevel(exp);
}