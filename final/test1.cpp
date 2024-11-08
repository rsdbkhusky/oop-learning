#include <iostream>
#include "include/Logic/LogicSudoku.h"

int main() {
    LogicSudoku ls = LogicSudoku::createLogicSudoku(3, 0.5);
    auto a = ls.getLenCell();
    auto b = ls.removeCellCandidates(1, 1, {2, 3, 4, 5, 6, 7});
    auto c = ls.setCellNum(1, 2, 4);
    return 0;
}
