//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM10_INT_H
#define PROBLEM10_INT_H


#include "Item.h"
class Int: public Item {
public:
    Int(int _mInt = 0);
    int getInt() const;
    virtual void transform() override;
protected:
    int mInt;
};


#endif //PROBLEM10_INT_H
