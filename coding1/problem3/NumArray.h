//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM3_NUMARRAY_H
#define PROBLEM3_NUMARRAY_H

class NumArrayItem;
class NumArray {
public:
    NumArray(int len);
    NumArray& head();
    NumArray& tail();
    NumArray& prev();
    NumArray& next();
    NumArray& set(int val);
    int val() const;
private:
    NumArray(const NumArray&) = delete;
    NumArray& operator=(const NumArray&) = delete;
    NumArrayItem* mHead;
    NumArrayItem* mTail;
    NumArrayItem* mCur;
};

#endif //PROBLEM3_NUMARRAY_H
