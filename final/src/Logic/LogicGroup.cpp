//
// Created by lenovo on 2024/11/8.
//

#include <algorithm>
#include "../../include/Logic/LogicGroup.h"
#include "../../include/Logic/LogicCell.h"
using std::find;
using std::end;

LogicGroup::LogicGroup(vector<LogicCell*>& _mCells): mCells(_mCells) {}

LogicGroup::~LogicGroup() = default;

int LogicGroup::getSize() const {
    return (int)mCells.size();
}

void LogicGroup::updateOneCandidatesByAllNums(vector<int>& candidates) const {
    for (auto cell: mCells) {
        if (cell->getStatus() == LogicCellStatus::CONFIRMED) {
            auto p = find(begin(candidates), end(candidates), cell->getNum());
            if (p != end(candidates)) candidates.erase(p);
        }
    }
}

void LogicGroup::updateAllCandidatesByOneNum(int num) const {
    for (auto cell: mCells) {
        if (cell->getStatus() == LogicCellStatus::PENDING) {
            cell->removeCandidates({num});
        }
    }
}
