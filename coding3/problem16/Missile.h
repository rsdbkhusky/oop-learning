//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM16_MISSILE_H
#define PROBLEM16_MISSILE_H

#include <string>
class LaunchMode;
class FlyBehavior;
using std::string;

class Missile {
public:
    Missile(const string& _mName, LaunchMode* _pLaunchMode, FlyBehavior* _pFlyBehavior);
    virtual ~Missile();
    Missile(const Missile& rhs);
    Missile& operator=(const Missile& rhs);
    virtual void simulate();
protected:
    string mName;
    LaunchMode* pLaunchMode; // 使用组合
    FlyBehavior* pFlyBehavior;
};


#endif //PROBLEM16_MISSILE_H
