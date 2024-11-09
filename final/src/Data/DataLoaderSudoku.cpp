//
// Created by lenovo on 2024/11/7.
//

#include <cmath>
#include <cassert>
#include "../../include/Data/DataLoaderSudoku.h"
using std::sqrt;

vector<vector<int>> DataLoaderSudoku::getSodoku(int index) const {
    string& data = *mData[index - 1];
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
            nums[i][j] = int(data[i * lenSudoku + j] - '0');
        }
    }
    return nums;
}
