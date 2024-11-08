//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATALOADER_H
#define FINAL_DATALOADER_H

#include <vector>
#include "../Utils/Singleton.h"
#include "DataProcessor.h"
using std::vector;

class DataLoader: public Singleton, public DataProcessor {
public:
    void loadData();
    int getCntData() const;
protected:
    DataLoader() = default;
    vector<string*> mData;
};


#endif //FINAL_DATALOADER_H
