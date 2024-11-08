//
// Created by lenovo on 2024/11/8.
//

#include "../../include/Utils/Singleton.h"

Singleton& Singleton::getInstance() {
    if (sInstance == nullptr) {
        sInstance = new Singleton();
    }
    return *sInstance;
}

void Singleton::destroyInstance() {
    delete sInstance;
    sInstance = nullptr;
}

Singleton* Singleton::sInstance = nullptr;