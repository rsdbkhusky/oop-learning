//
// Created by lenovo on 2024/11/28.
//

#include <algorithm>
#include "Shark.h"
#include "Cat.h"
using std::min;

Shark::Shark(int _mWeight): mWeight(_mWeight) {}

int Shark::getExp(const Cat& cat) {
    return -min(cat.getExp(), 5 * mWeight);
}