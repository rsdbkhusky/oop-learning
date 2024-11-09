//
// Created by lenovo on 2024/11/7.
//

#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cassert>
#include "../../include/Data/DataManager.h"
namespace fs = std::filesystem;
using std::sort;
using std::begin;
using std::end;
using std::endl;

void DataManager::loadFileList() {
    mFileList.clear();
    if (fs::exists(sFolderPath) && fs::is_directory(sFolderPath)) {
        for (const auto& entry : fs::directory_iterator(sFolderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == sExtension) {
                mFileList.insert(entry.path().stem().string());
            }
        }
    }
}

int DataManager::getCntFile() const {
    return (int)mFileList.size();
}

const set<string>& DataManager::getFileList() const {
    return mFileList;
}

void DataManager::loadFile(const string& fileName) {
    assert(mFileList.find(fileName) != end(mFileList));
    mFileName = fileName;
    std::ifstream file(sFolderPath + fileName + sExtension);
    mLines.clear();
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
            if (line.empty()) continue;
            mLines.push_back(line);
        }
        file.close();
    }
}

int DataManager::getCntLine() const {
    return (int)mLines.size();
}

void DataManager::removeFile(const string& fileName) {
    assert(mFileList.find(fileName) != end(mFileList));
    mFileList.erase(fileName);
    string filePath = sFolderPath + fileName + sExtension;
    std::remove(filePath.c_str());
}

void DataManager::addFile() {
    assert(mFileList.find(mFileName) == end(mFileList));
    mFileList.insert(mFileName);
    std::ofstream file(sFolderPath + mFileName + sExtension);
    if (file.is_open()) {
        for (const auto& line: mLines) {
            file << line << endl;
        }
        file.close();
    }
}