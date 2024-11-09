//
// Created by lenovo on 2024/11/9.
//

#include <iostream>
#include "include/Data/DataManagerSudoku.h"
using std::cout;
using std::endl;

int main() {
    DataManagerSudoku& dls = DataManagerSudoku::Singleton<DataManagerSudoku>::getInstance();
    dls.loadFileList();
    auto fileList = dls.getFileList();
    int p = 0;
    for (auto i: fileList) {
        ++p;
        if (p == 2) {
            dls.loadFile(i);
            auto sdk = dls.getSudoku();
            dls.setSudoku(sdk);
            dls.addFile();
        }
    }
    return 0;
}
