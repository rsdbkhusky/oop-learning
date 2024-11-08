//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_LOGICCELL_H
#define FINAL_LOGICCELL_H

#include <vector>
using std::vector;

enum class LogicCellStatus {
    PENDING, CONFIRMED,
};

enum class LogicReturnValue {
    SUCCESS,
    WARNING_NOTINCANDIDATE,
    ERROR_CELLSTATUSCONFLICT, ERROR_NOTINCANDIDATE,
};

class LogicCell {
public:
    explicit LogicCell(int _mNum);
    explicit LogicCell(const vector<int>& _mCandidates);
    LogicCellStatus getStatus() const;
    int getNum() const;
    const vector<int>& getCandidates() const;
    LogicReturnValue setNum(int num);
    LogicReturnValue removeCandidates(const vector<int>& nums);
    LogicReturnValue resetCandidates(const vector<int>& candidates);
private:
    LogicCellStatus mStatus;
    int mNum;
    vector<int> mCandidates;
};

#endif //FINAL_LOGICCELL_H
