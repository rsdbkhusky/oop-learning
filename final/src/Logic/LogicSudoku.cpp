//
// Created by lenovo on 2024/11/5.
//

#include <cassert>
#include <cmath>
#include <numeric>
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/Logic/LogicRow.h"
#include "../../include/Logic/LogicColumn.h"
#include "../../include/Logic/LogicBlock.h"
#include "../../include/Logic/LogicCell.h"
using std::sqrt;
using std::iota;

int LogicSudoku::getBlockIndex(int x, int y) const {
    int lenCell = getLenCell();
    return ((x - 1) / lenCell) * lenCell + ((y - 1) / lenCell) + 1;
}

LogicSudoku::LogicSudoku(int _lenCell) {
    mCells.resize(_lenCell * _lenCell);
    for (auto i: mCells) {
        i.resize(_lenCell * _lenCell);
    }
    mColumns.resize(_lenCell * _lenCell);
    mRows.resize(_lenCell * _lenCell);
    mBlocks.resize(_lenCell * _lenCell);
}

LogicSudoku::~LogicSudoku() = default;

int LogicSudoku::getLenCell() const {
    return (int)sqrt(mCells.size());
}

LogicReturnValue LogicSudoku::setCellNum(int x, int y, int num) {
    LogicReturnValue result = mCells[x - 1][y - 1]->setNum(num);
    if (result != LogicReturnValue::SUCCESS) return result;
    mRows[x - 1]->updateAllCandidatesByOneNum(num);
    mColumns[y - 1]->updateAllCandidatesByOneNum(num);
    mBlocks[getBlockIndex(x, y) - 1]->updateAllCandidatesByOneNum(num);
    return result;
}

LogicReturnValue LogicSudoku::removeCellCandidates(int x, int y, vector<int> nums) {
    return mCells[x - 1][y - 1]->removeCandidates(nums);
}

LogicReturnValue LogicSudoku::resetCellCandidates(int x, int y) {
    if (mCells[x - 1][y - 1]->getStatus() != LogicCellStatus::PENDING) {
        return LogicReturnValue::ERROR_CELLSTATUSCONFLICT;
    }
    vector<int> candidates(getLenCell() * getLenCell());
    iota(begin(candidates), end(candidates), 1);
    mRows[x - 1]->updateOneCandidatesByAllNums(candidates);
    mColumns[y - 1]->updateOneCandidatesByAllNums(candidates);
    mBlocks[getBlockIndex(x, y) - 1]->updateOneCandidatesByAllNums(candidates);
    mCells[x - 1][y - 1]->resetCandidates(candidates);
    return LogicReturnValue::SUCCESS;
}
