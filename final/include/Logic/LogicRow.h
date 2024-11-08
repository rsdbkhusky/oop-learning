//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_LOGICROW_H
#define FINAL_LOGICROW_H

#include "LogicGroup.h"

class LogicRow: public LogicGroup {
public:
    explicit LogicRow(vector<LogicCell*>& _mCells);
};


#endif //FINAL_LOGICROW_H
