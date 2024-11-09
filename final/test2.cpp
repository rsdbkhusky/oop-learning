//
// Created by lenovo on 2024/11/8.
//

#include <iostream>
#include "include/Data/DataLoaderSudoku.h"
using std::cout;
using std::endl;

int main() {
    DataLoaderSudoku& dls = DataLoaderSudoku::Singleton<DataLoaderSudoku>::getInstance();
    dls.loadData();
    for (int i = 1; i <= dls.getCntData(); ++i) {
        auto a = dls.getSodoku(i);
    }
    return 0;
}
