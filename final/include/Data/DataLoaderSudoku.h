//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATALOADERSUDOKU_H
#define FINAL_DATALOADERSUDOKU_H

#include "DataLoader.h"

class DataLoaderSudoku: public DataLoader {
public:
    vector<vector<int>> getSodoku(int index) const;
};


#endif //FINAL_DATALOADERSUDOKU_H
