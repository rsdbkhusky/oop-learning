//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_LOGICBLOCK_H
#define FINAL_LOGICBLOCK_H

#include "LogicGroup.h"

class LogicBlock: public LogicGroup {
public:
    explicit LogicBlock(vector<LogicCell*>& _mCells);
};

#endif //FINAL_LOGICBLOCK_H
