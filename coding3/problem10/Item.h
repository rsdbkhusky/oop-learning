//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM10_ITEM_H
#define PROBLEM10_ITEM_H


#include "IItem.h"
class Item: public IItem {
public:
    virtual void transform() override;
};


#endif //PROBLEM10_ITEM_H
