//
// Created by lenovo on 2024/11/7.
//

#include <cmath>
#include <cassert>
#include <ctime>
#include <iomanip>
#include "../../include/Data/DataManagerSudoku.h"
using std::sqrt;

vector<vector<int>> DataManagerSudoku::getSudoku() const {
    assert(getCntLine() == 2);
    vector<int> data;
    std::istringstream iss(mLines[1]);
    string temp;
    while (iss >> temp) {
        data.push_back(stoi(temp));
    }
    int lenData = (int)data.size();
    int lenSudoku = (int)sqrt(lenData);
    assert(lenSudoku * lenSudoku == lenData);
    vector<vector<int>> nums;
    nums.resize(lenSudoku);
    for (int i = 0; i < lenSudoku; ++i) {
        nums[i].resize(lenSudoku);
    }
    for (int i = 0; i < lenSudoku; ++i) {
        for (int j = 0; j < lenSudoku; ++j) {
            nums[i][j] = int(data[i * lenSudoku + j]);
        }
    }
    return nums;
}

void DataManagerSudoku::setSudoku(const vector<vector<int>>& nums) {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y%m%d%H%M%S");
    mFileName = oss.str();
    mLines.clear();
    mLines.push_back(mFileName);
    string data;
    for (auto& i: nums) {
        for (auto& j: i) {
            data += std::to_string(j) + " ";
        }
    }
    mLines.push_back(data);
}