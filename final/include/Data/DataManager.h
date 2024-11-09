//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_DATAMANAGER_H
#define FINAL_DATAMANAGER_H

#include <vector>
#include <set>
#include "../Utils/Singleton.h"
#include "DataConfig.h"
using std::vector;
using std::set;

class DataManager: public Singleton<DataManager>, public DataConfig {
    friend class Singleton<DataManager>;
public:
    void loadFileList();
    int getCntFile() const;
    const set<string>& getFileList() const;
    void loadFile(const string& fileName);
    int getCntLine() const;
    void removeFile(const string& fileName);
    void addFile();
protected:
    DataManager() = default;
    virtual ~DataManager() override = default;
    set<string> mFileList;
    string mFileName;
    vector<string> mLines;
};


#endif //FINAL_DATAMANAGER_H
