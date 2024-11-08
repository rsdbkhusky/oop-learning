//
// Created by lenovo on 2024/11/7.
//

#include <fstream>
#include "../../include/Data/DataLoader.h"
using std::ifstream;

void DataLoader::loadData() {
    string filename = sFilePath;
    ifstream file(filename);
    mData.clear();
    if (file.is_open()) {
        int n;
        file >> n;
        file.ignore();
        string line;
        for (int i = 0; i < n; ++i) {
            std::getline(file, line);
            mData.push_back(new string(line));
        }
        file.close();
    }
}

int DataLoader::getCntData() const {
    return (int)mData.size();
}