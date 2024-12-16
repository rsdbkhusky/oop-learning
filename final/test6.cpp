//
// Created by lenovo on 2024/12/16.
//

#include "include/Output/OutputDisplayerConsole.h"
#include "include/UI/UISudoku.h"
#include "include/UI/UIButton.h"
#include "include/UI/UContainerHorizontal.h"
#include "include/UI/UContainerVertical.h"

int main() {
    OutputDisplayer& od = Singleton<OutputDisplayerConsole>::getInstance();
    IUI* a = new UIButton("abc");
    IUI* b = new UIButton("cao n1 ma!");
    IUI* c = new UIButton("CCB!");
    IUI* d = new UContainerHorizontal({a, b, c});
    IUI* e = new UIButton("fuck");
    LogicSudoku* ls = LogicSudoku::createLogicSudoku(3, 0.5);
    IUI* f = new UISudoku(ls);
    IUI* g = new UContainerVertical({d, e, f});
    od.displayAllUI(*g);
}