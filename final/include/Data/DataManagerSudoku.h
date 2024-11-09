//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATAMANAGERSUDOKU_H
#define FINAL_DATAMANAGERSUDOKU_H

#include "DataManager.h"

class DataManagerSudoku: public Singleton<DataManagerSudoku>, public DataManager {
    friend class Singleton<DataManagerSudoku>;
public:
    vector<vector<int>> getSudoku() const;
    void setSudoku(const vector<vector<int>>& nums);
protected:
    DataManagerSudoku() = default;
    virtual ~DataManagerSudoku() override = default;
};


#endif //FINAL_DATAMANAGERSUDOKU_H
