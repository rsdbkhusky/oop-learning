//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_UISUDOKU_H
#define FINAL_UISUDOKU_H

#include "UI.h"
#include "../Logic/LogicSudoku.h"

class UISudoku: public UI {
public:
    UISudoku(LogicSudoku* _pLogicSudoku);
    const LogicSudoku& getLogicSudoku() const;
protected:
    LogicSudoku* pLogicSudoku;
};


#endif //FINAL_UISUDOKU_H
