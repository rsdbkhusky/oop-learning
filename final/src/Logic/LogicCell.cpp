//
// Created by lenovo on 2024/11/5.
//

#include <cassert>
#include <algorithm>
#include "../../include/Logic/LogicCell.h"
using std::find;
using std::begin;
using std::end;

LogicCell::LogicCell(int _mNum) {
    mStatus = LogicCellStatus::CONFIRMED;
    mNum = _mNum;
}

LogicCell::LogicCell(const vector<int> &_mCandidates) {
    mStatus = LogicCellStatus::PENDING;
    mCandidates = _mCandidates;
}

LogicCellStatus LogicCell::getStatus() const {
    return mStatus;
}

int LogicCell::getNum() const {
    assert(mStatus == LogicCellStatus::CONFIRMED);
    return mNum;
}

const vector<int> &LogicCell::getCandidates() const {
    assert(mStatus == LogicCellStatus::PENDING);
    return mCandidates;
}

LogicReturnValue LogicCell::setNum(int num) {
    if (mStatus != LogicCellStatus::PENDING) {
        return LogicReturnValue::ERROR_CELLSTATUSCONFLICT;
    }
    if (find(begin(mCandidates), end(mCandidates), num) == end(mCandidates)) {
        return LogicReturnValue::ERROR_NOTINCANDIDATE;
    }
    mStatus = LogicCellStatus::CONFIRMED;
    mNum = num;
    return LogicReturnValue::SUCCESS;
}

LogicReturnValue LogicCell::removeCandidates(const vector<int> &nums) {
    if (mStatus != LogicCellStatus::PENDING) {
        return LogicReturnValue::ERROR_CELLSTATUSCONFLICT;
    }
    int cntNotin = 0;
    for (auto num: nums) {
        auto p = find(begin(mCandidates), end(mCandidates), num);
        if (p == end(mCandidates)) ++cntNotin;
        else mCandidates.erase(p);
    }
    if (cntNotin == nums.size()) return LogicReturnValue::ERROR_NOTINCANDIDATE;
    else if (cntNotin > 0) return LogicReturnValue::WARNING_NOTINCANDIDATE;
    else return LogicReturnValue::SUCCESS;
}

LogicReturnValue LogicCell::resetCandidates(const vector<int> &candidates) {
    if (mStatus != LogicCellStatus::PENDING) {
        return LogicReturnValue::ERROR_CELLSTATUSCONFLICT;
    }
    mCandidates = candidates;
    return LogicReturnValue::SUCCESS;
}