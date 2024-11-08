//
// Created by lenovo on 2024/11/8.
//

#ifndef FINAL_LOGICGROUP_H
#define FINAL_LOGICGROUP_H

#include<vector>
using std::vector;
class LogicCell;

class LogicGroup {
public:
    explicit LogicGroup(vector<LogicCell*>& _mCells);
    virtual ~LogicGroup();
    int getSize() const;
    virtual void updateOneCandidatesByAllNums(vector<int>& candidates) const;
    virtual void updateAllCandidatesByOneNum(int num) const;
private:
    vector<LogicCell*> mCells;
};

#endif //FINAL_LOGICGROUP_H
