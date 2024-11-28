//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_CAT_H
#define PROBLEM12_CAT_H

class Fish;

class Cat {
public:
    static int getOneLevelExp();
    Cat(int _mLevel, int _mExp);
    int getLevel() const;
    int getExp() const;
    void CatchFish(Fish& fish);
private:
    void addExpAndLevel(int exp);
    int mLevel;
    int mExp;
};


#endif //PROBLEM12_CAT_H
