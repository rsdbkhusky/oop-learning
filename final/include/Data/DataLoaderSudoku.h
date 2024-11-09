//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATALOADERSUDOKU_H
#define FINAL_DATALOADERSUDOKU_H

#include "DataLoader.h"

class DataLoaderSudoku: public Singleton<DataLoaderSudoku>, public DataLoader {
    friend class Singleton<DataLoaderSudoku>;
public:
    vector<vector<int>> getSudoku() const;
protected:
    DataLoaderSudoku() = default;
    virtual ~DataLoaderSudoku() override = default;
};


#endif //FINAL_DATALOADERSUDOKU_H
