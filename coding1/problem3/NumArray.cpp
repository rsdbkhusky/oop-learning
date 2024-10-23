//
// Created by lenovo on 2024/10/22.
//

#include <cassert>
#include "NumArrayItem.h"
#include "NumArray.h"

NumArray::NumArray(int len) {
    assert(len >= 1);
    mHead = new NumArrayItem(1);
    NumArrayItem* last = mHead;
    NumArrayItem* cur = nullptr;
    for (int i = 2; i <= len; ++i) {
        cur = new NumArrayItem(i, last);
        last->setNext(cur);
        last = cur;
    }
    mTail = cur;
}
NumArray& NumArray::head() {
    mCur = mHead;
    return *this;
}
NumArray& NumArray::tail() {
    mCur = mTail;
    return *this;
}
NumArray& NumArray::prev() {
    mCur = mCur->prev();
    return *this;
}
NumArray& NumArray::next() {
    mCur = mCur->next();
    return *this;
}
NumArray& NumArray::set(int val) {
    mCur->setNum(val);
    return *this;
}
int NumArray::val() const {
    return mCur->getNum();
}