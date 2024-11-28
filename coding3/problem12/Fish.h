//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM12_FISH_H
#define PROBLEM12_FISH_H


class Cat;

class Fish {
public:
    virtual ~Fish() = default;
    virtual int getExp(const Cat& cat);
};


#endif //PROBLEM12_FISH_H
