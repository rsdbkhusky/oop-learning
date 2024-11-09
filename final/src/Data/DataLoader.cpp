//
// Created by lenovo on 2024/11/7.
//

#include <fstream>
#include <filesystem>
#include <algorithm>
#include "../../include/Data/DataLoader.h"
using std::ifstream;
namespace fs = std::filesystem;
using std::sort;
using std::begin;
using std::end;

void DataLoader::loadFileList() {
    mFileList.clear();
    if (fs::exists(sFolderPath) && fs::is_directory(sFolderPath)) {
        for (const auto& entry : fs::directory_iterator(sFolderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == sExtension) {
                mFileList.push_back(new string(entry.path().stem().string()));
            }
        }
    }
    sort(begin(mFileList), end(mFileList),
         [](const string* lhs, const string* rhs) -> bool {
        return (*lhs) < (*rhs);
    });
}

int DataLoader::getCntFile() const {
    return (int)mFileList.size();
}

void DataLoader::loadData(int index) {
    ifstream file(sFolderPath + *mFileList[index - 1] + sExtension);
    mLines.clear();
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
            if (line.empty()) continue;
            mLines.push_back(new string(line));
        }
        file.close();
    }
}

int DataLoader::getCntLine() const {
    return (int)mLines.size();
}