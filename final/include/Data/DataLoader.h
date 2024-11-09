//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATALOADER_H
#define FINAL_DATALOADER_H

#include <vector>
#include "../Utils/Singleton.h"
#include "DataProcessor.h"
using std::vector;

class DataLoader: public Singleton<DataLoader>, public DataProcessor {
    friend class Singleton<DataLoader>;
public:
    void loadFileList();
    int getCntFile() const;
    void loadData(int index);
    int getCntLine() const;
protected:
    DataLoader() = default;
    virtual ~DataLoader() override = default;
    vector<string*> mFileList;
    vector<string*> mLines;
};


#endif //FINAL_DATALOADER_H
