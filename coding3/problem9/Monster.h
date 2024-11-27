//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM9_MONSTER_H
#define PROBLEM9_MONSTER_H

class Monster {
public:
    Monster(int _mHitpoint = 0, int _mDamage = 0, int _mDefense = 0);
    virtual ~Monster() = default;
    int getHp() const;
    void setHp(int hitpoint);
    int getDf() const;
    bool fight(Monster& enemy);
    virtual bool isAlive();
protected:
    virtual void attack(Monster& enemy) = 0;
    int mHitpoint;
    int mDamage;
    int mDefense;
};

#endif //PROBLEM9_MONSTER_H
