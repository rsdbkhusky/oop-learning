//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM13_BOX_H
#define PROBLEM13_BOX_H

class Role;
class Solider;
class Mage;

class Box {
public:
    virtual ~Box() = default;
    void beOpened(Role& role);
    virtual void beOpenedBySolider(Solider& solider) = 0;
    virtual void beOpenedByMage(Mage& mage) = 0;
};


#endif //PROBLEM13_BOX_H
