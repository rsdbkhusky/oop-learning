//
// Created by lenovo on 2024/10/22.
//

#include "NumArrayItem.h"

NumArrayItem::NumArrayItem(int _mNum, NumArrayItem *_mPrev, NumArrayItem *_mNext):mNum(_mNum), mPrev(_mPrev), mNext(_mNext) {
    if (mPrev == nullptr) mPrev = this;
    if (mNext == nullptr) mNext = this;
}
void NumArrayItem::setNum(int num) {
    mNum = num;
}
int NumArrayItem::getNum() const {
    return mNum;
}
void NumArrayItem::setPrev(NumArrayItem* prev) {
    mPrev = prev;
}
void NumArrayItem::setNext(NumArrayItem* next) {
    mNext = next;
}
NumArrayItem* NumArrayItem::prev() const {
    return mPrev;
}
NumArrayItem* NumArrayItem::next() const {
    return mNext;
}
