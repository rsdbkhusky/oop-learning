//
// Created by lenovo on 2024/11/5.
//

#include <cassert>
#include <cmath>
#include <numeric>
#include <random>
#include <algorithm>
#include <unordered_set>
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/Logic/LogicRow.h"
#include "../../include/Logic/LogicColumn.h"
#include "../../include/Logic/LogicBlock.h"
#include "../../include/Logic/LogicCell.h"
using std::sqrt;
using std::iota;
using std::mt19937;
using std::random_device;
using std::shuffle;
using std::uniform_int_distribution;
using std::unordered_set;

int LogicSudoku::getBlockIndex(int x, int y) const {
    int lenCell = getLenCell();
    return ((x - 1) / lenCell) * lenCell + ((y - 1) / lenCell) + 1;
}

vector<vector<int>> LogicSudoku::genSudoku(int lenCell, double zeroRatio) {
    int size = lenCell * lenCell;
    vector<vector<int>> nums = vector<vector<int>>(size, vector<int>(size, 0));
    random_device rd;
    mt19937 g(rd());
    for (int i = 0; i < size; i += lenCell) {
        vector<int> numbers(size);
        iota(numbers.begin(), numbers.end(), 1);
        shuffle(numbers.begin(), numbers.end(), g);
        for (int r = 0; r < lenCell; ++r) {
            for (int c = 0; c < lenCell; ++c) {
                nums[i + r][i + c] = numbers[r * lenCell + c];
            }
        }
    }
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (nums[row][col] == 0) {
                vector<int> numbers(size);
                iota(numbers.begin(), numbers.end(), 1);
                shuffle(numbers.begin(), numbers.end(), g);
                for (int num : numbers) {
                    bool isSafe = true;
                    for (int k = 0; k < size; ++k) {
                        if (nums[row][k] == num || nums[k][col] == num) {
                            isSafe = false;
                            break;
                        }
                    }
                    if (isSafe) {
                        int startRow = row / lenCell * lenCell;
                        int startCol = col / lenCell * lenCell;
                        for (int r = 0; r < lenCell; ++r) {
                            for (int c = 0; c < lenCell; ++c) {
                                if (nums[startRow + r][startCol + c] == num) {
                                    isSafe = false;
                                    break;
                                }
                            }
                            if (!isSafe) break;
                        }
                    }
                    if (isSafe) {
                        nums[row][col] = num;
                        break;
                    }
                }
            }
        }
    }
    int totalCells = size * size;
    int numRemove = (int)round(totalCells * zeroRatio);
    uniform_int_distribution<> dist(0, size - 1);
    while (numRemove > 0) {
        int row = dist(g);
        int col = dist(g);
        if (nums[row][col] != 0) {
            nums[row][col] = 0;
            numRemove--;
        }
    }
    return nums;
}

bool LogicSudoku::checkSudoku(const vector<vector<int>>& _nums) {
    int lenSudoku = (int)_nums.size();
    if (lenSudoku <= 0) return true;
    if ((int)sqrt(lenSudoku) * (int)sqrt(lenSudoku) != lenSudoku) return true;
    for (int i = 0; i < lenSudoku; ++i) {
        if (lenSudoku != (int)_nums[i].size()) return true;
        for (int j = 0; j < lenSudoku; ++j) {
            if (_nums[i][j] != 0 && (_nums[i][j] < 1 || _nums[i][j] > lenSudoku)) {
                return true;
            }
        }
    }
    for (int i = 0; i < lenSudoku; ++i) {
        unordered_set<int> rowSet, colSet;
        for (int j = 0; j < lenSudoku; ++j) {
            if (_nums[i][j] != 0) {
                if (rowSet.find(_nums[i][j]) != rowSet.end()) {
                    return true;
                }
                rowSet.insert(_nums[i][j]);
            }
            if (_nums[j][i] != 0) {
                if (colSet.find(_nums[j][i]) != colSet.end()) {
                    return true;
                }
                colSet.insert(_nums[j][i]);
            }
        }
    }
    int lenCell = (int)sqrt(lenSudoku);
    for (int boxRow = 0; boxRow < lenCell; ++boxRow) {
        for (int boxCol = 0; boxCol < lenCell; ++boxCol) {
            unordered_set<int> boxSet;
            for (int i = 0; i < lenCell; ++i) {
                for (int j = 0; j < lenCell; ++j) {
                    int num = _nums[boxRow * lenCell + i][boxCol * lenCell + j];
                    if (num != 0) {
                        if (boxSet.find(num) != boxSet.end()) {
                            return true;
                        }
                        boxSet.insert(num);
                    }
                }
            }
        }
    }
    return false;
}

LogicSudoku::LogicSudoku(const vector<vector<int>>& _nums) {
    int lenSudoku = (int)_nums.size();
    mCells.resize(lenSudoku);
    for (int i = 0; i < lenSudoku; ++i) {
        mCells[i].resize(lenSudoku);
    }
    mColumns.resize(lenSudoku);
    mRows.resize(lenSudoku);
    mBlocks.resize(lenSudoku);
    for (int i = 0; i < lenSudoku; ++i) {
        for (int j = 0; j < lenSudoku; ++j) {
            mCells[i][j] = new LogicCell(_nums[i][j]);
        }
    }
    for (int i = 0; i < lenSudoku; ++i) {
        mRows[i] = new LogicRow(mCells[i]);
    }
    for (int j = 0; j < lenSudoku; ++j) {
        vector<LogicCell*> temp(lenSudoku);
        for (int i = 0; i < lenSudoku; ++i) {
            temp[i] = mCells[i][j];
        }
        mColumns[j] = new LogicColumn(temp);
    }
    for (int k = 0; k < lenSudoku; ++k) {
        int lenCell = (int)sqrt(lenSudoku);
        int x = (k / lenCell) * lenCell;
        int y = (k % lenCell) * lenCell;
        vector<LogicCell*> temp;
        for (int i = 0; i < lenCell; ++i) {
            for (int j = 0; j < lenCell; ++j) {
                temp.push_back(mCells[x + i][y + j]);
            }
        }
        mBlocks[k] = new LogicBlock(temp);
    }
    for (int i = 0; i < lenSudoku; ++i) {
        for (int j = 0; j < lenSudoku; ++j) {
            if (_nums[i][j] == 0) resetCellCandidates(i + 1, j + 1);
        }
    }
}

LogicSudoku LogicSudoku::createLogicSudoku(int _lenCell, double _zeroRatio) {
    assert(_lenCell > 0);
    assert(_zeroRatio >= 0 && _zeroRatio <= 1);
    return LogicSudoku(genSudoku(_lenCell, _zeroRatio));
}

LogicSudoku LogicSudoku::createLogicSudoku(const vector<vector<int>>& _nums) {
    assert(LogicSudoku::checkSudoku(_nums) == 0);
    return LogicSudoku(_nums);
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

LogicReturnValue LogicSudoku::removeCellCandidates(int x, int y, const vector<int>& nums) {
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
