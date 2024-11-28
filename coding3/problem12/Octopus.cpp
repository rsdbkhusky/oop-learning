//
// Created by lenovo on 2024/11/28.
//

#include "Octopus.h"

Octopus::Octopus(int _mWeight): mWeight(_mWeight) {}

int Octopus::getExp(const Cat& cat) {
    return 2 * mWeight;
}