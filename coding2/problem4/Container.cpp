//
// Created by lenovo on 2024/11/6.
//

#include <cassert>
#include "Container.h"

Container::Container(int defVal) {
    int len = sizeof(items) / sizeof(items[0]);
    for (int i = 0; i < len; ++i) {
        items[i] = defVal;
    }
}

int& Container::Item(int index) {
    assert(index >= 0);
    assert(index < sizeof(items) / sizeof(items[0]));
    return items[index];
}

const int &Container::Item(int index) const {
    assert(index >= 0);
    assert(index < sizeof(items) / sizeof(items[0]));
    return items[index];
}