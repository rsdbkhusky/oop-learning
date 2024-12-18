//
// Created by lenovo on 2024/12/18.
//

#include <iostream>
#include "../../include/Output/OutputDisplayerConsole.h"
#include "../../include/Output/OutputProcessor.h"
using std::cout;
using std::endl;

void OutputDisplayerConsole::displayAllUI(IUI& iui) {
//    system("cls");
//    vector<vector<char>> vvc = OutputProcessor::iui2vvc(iui);
//    for (int i = 0; i < vvc.size(); ++i) {
//        for (int j = 0; j < vvc[i].size(); ++j) {
//            putchar(vvc[i][j]);
//        }
//        putchar('\n');
//    }
    system("cls");
    vector<vector<char>> vvc = OutputProcessor::iui2vvc(iui);
    for (int i = 0; i < vvc.size(); ++i) {
        for (int j = 0; j < vvc[i].size(); ++j) {
            cout << vvc[i][j];
        }
        cout << endl;
    }
}