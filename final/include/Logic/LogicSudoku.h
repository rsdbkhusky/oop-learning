//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_LOGICSUDOKU_H
#define FINAL_LOGICSUDOKU_H

#include<vector>
using std::vector;
enum class LogicCellStatus;
enum class LogicReturnValue;
class LogicCell;
class LogicColumn;
class LogicRow;
class LogicBlock;

class LogicSudoku {
public:
    explicit LogicSudoku(int _lenCell);
    ~LogicSudoku();
    int getLenCell() const;
    LogicReturnValue setCellNum(int x, int y, int num);
    LogicReturnValue removeCellCandidates(int x, int y, vector<int> nums);
    LogicReturnValue resetCellCandidates(int x, int y);
private:
    int getBlockIndex(int x, int y) const;
    vector<vector<LogicCell*>> mCells;
    vector<LogicRow*> mRows;
    vector<LogicColumn*> mColumns;
    vector<LogicBlock*> mBlocks;
};

#endif //FINAL_LOGICSUDOKU_H
