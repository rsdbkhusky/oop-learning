//
// Created by lenovo on 2024/11/9.
//

#include <iostream>
#include "include/Data/DataLoaderSudoku.h"
using std::cout;
using std::endl;

int main() {
    DataLoaderSudoku& dls = DataLoaderSudoku::Singleton<DataLoaderSudoku>::getInstance();
    dls.loadFileList();
//    for (auto i: dls.mFileList) {
//        cout << '#' << *i << '@' << endl;
//    }
    for (int i = 1; i <= dls.getCntFile(); ++i) {
        dls.loadData(i);
        auto a = dls.getSudoku();
    }
    return 0;
}
