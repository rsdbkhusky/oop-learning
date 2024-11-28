//
// Created by lenovo on 2024/11/28.
//

#include <iostream>
#include <algorithm>
#include "Missile.h"
#include "LaunchMode.h"
#include "FlyBehavior.h"
using std::cout;
using std::endl;
using std::swap;

Missile::Missile(const string& _mName, LaunchMode* _pLaunchMode, FlyBehavior* _pFlyBehavior): mName(_mName), pLaunchMode(_pLaunchMode), pFlyBehavior(_pFlyBehavior) {}

Missile::~Missile() {
    delete pLaunchMode;
    delete pFlyBehavior;
}

Missile::Missile(const Missile& rhs): mName(rhs.mName) {
    pLaunchMode = new LaunchMode(*rhs.pLaunchMode);
    pFlyBehavior = new FlyBehavior(*rhs.pFlyBehavior);
}

Missile& Missile::operator=(const Missile& rhs) {
    Missile temp(rhs);
    swap(pLaunchMode, temp.pLaunchMode);
    swap(pFlyBehavior, temp.pFlyBehavior);
    return *this;
}

void Missile::simulate() {
    cout << mName << endl;
    pLaunchMode->simulate();
    pFlyBehavior->simulate();
    cout << endl;
}
