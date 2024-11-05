//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_SUDOKU_H
#define FINAL_SUDOKU_H

#include<vector>
using std::vector;
class Cell;
class Column;
class Row;
class Block;

class Sudoku {
private:
    vector<vector<Cell*>> mCells;
    vector<Column*> mColumns;
    vector<Row*> mRows;
    vector<Block*> mBlocks;
};

#endif //FINAL_SUDOKU_H
