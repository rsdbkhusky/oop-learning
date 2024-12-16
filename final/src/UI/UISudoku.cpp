//
// Created by lenovo on 2024/11/7.
//

#include "../../include/UI/UISudoku.h"

UISudoku::UISudoku(LogicSudoku* _pLogicSudoku): pLogicSudoku(_pLogicSudoku) {}

const LogicSudoku& UISudoku::getLogicSudoku() const {
    return *pLogicSudoku;
}