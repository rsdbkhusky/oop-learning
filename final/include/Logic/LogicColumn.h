//
// Created by lenovo on 2024/11/5.
//

#ifndef FINAL_LOGICCOLUMN_H
#define FINAL_LOGICCOLUMN_H

#include "LogicGroup.h"

class LogicColumn: public LogicGroup {
public:
    explicit LogicColumn(vector<LogicCell*>& _mCells);
};


#endif //FINAL_LOGICCOLUMN_H
