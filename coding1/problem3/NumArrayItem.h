//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM3_NUMARRAYITEM_H
#define PROBLEM3_NUMARRAYITEM_H

class NumArrayItem {
public:
    explicit NumArrayItem(int _nNum = 0, NumArrayItem* _mPrev = nullptr, NumArrayItem* _mNext = nullptr);
    void setNum(int num);
    int getNum() const;
    void setPrev(NumArrayItem* prev);
    void setNext(NumArrayItem* next);
    NumArrayItem* prev() const;
    NumArrayItem* next() const;
private:
    int mNum;
    NumArrayItem* mPrev;
    NumArrayItem* mNext;
};

#endif //PROBLEM3_NUMARRAYITEM_H
