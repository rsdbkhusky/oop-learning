//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM13_ROLE_H
#define PROBLEM13_ROLE_H

class Box;

class Role {
public:
    Role(int _mHp, int _mMoney);
    virtual ~Role() = default;
    int getHp() const;
    void setHp(int hp);
    int getMoney() const;
    void setMoney(int money);
    void openBox(Box& box);
private:
    int mHp;
    int mMoney;
};


#endif //PROBLEM13_ROLE_H
