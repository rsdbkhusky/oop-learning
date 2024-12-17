//
// Created by lenovo on 2024/11/7.
//

#include "../../include/Output/OutputDisplayerConsole.h"
#include "../../include/Output/OutputProcessor.h"

void OutputDisplayerConsole::displayAllUI(IUI& iui) {
    system("cls");
    vector<vector<char>> vvc = OutputProcessor::iui2vvc(iui);
    for (int i = 0; i < vvc.size(); ++i) {
        for (int j = 0; j < vvc[i].size(); ++j) {
            putchar(vvc[i][j]);
        }
        putchar('\n');
    }
}