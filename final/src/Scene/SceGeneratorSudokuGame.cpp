//
// Created by lenovo on 2024/12/18.
//

#include "../../include/Scene/SceGeneratorSudokuGame.h"
#include "../../include/Application/Application.h"
#include "../../include/Scene/Scene.h"
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/UI/UI.h"
#include "../../include/UI/UISudoku.h"
#include "../../include/UI/UIText.h"
#include "../../include/UI/UIButtonSwitchScene.h"
#include "../../include/UI/UIArchiveList.h"
#include "../../include/UI/UContainerVertical.h"
#include "../../include/UI/UContainerHorizontal.h"

Scene* SceGeneratorSudokuGame::genScene(Application* application, SceGenerParaList* sceGenerParaList) {
    Scene* sceneGame = new Scene(application);

    LogicSudoku* logicSudoku = LogicSudoku::createLogicSudoku(3, 0.5);
    UI* iuiA = new UISudoku(logicSudoku, sceneGame);
    UI* iuiB = new UIText("Welcome to RsdbkHusky's Sudoku!", sceneGame);
    UI* iuiC = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("exit")}, sceneGame);
    IUI* iuiD = new UContainerHorizontal({iuiB, iuiC});
    UI* iuiDE1 = new UIText(UIArchiveList::vc2string(UIArchiveList::vcFillGivenLength
                                                             (UIArchiveList::string2vc("exit: Exit the current game."), 60)));
    UI* iuiDE2 = new UIText(UIArchiveList::vc2string(UIArchiveList::vcFillGivenLength
                                                             (UIArchiveList::string2vc("replay: Replay the current game."), 60)));
    UI* iuiDE3 = new UIText(UIArchiveList::vc2string(UIArchiveList::vcFillGivenLength
                                                             (UIArchiveList::string2vc("save: Save the current game."), 60)));
    UI* iuiDE4 = new UIText(UIArchiveList::vc2string(UIArchiveList::vcFillGivenLength
                                                             (UIArchiveList::string2vc("set <rowindex>,<colindex>,<num>: Set num."), 60)));
    UI* iuiDE5 = new UIText(UIArchiveList::vc2string(UIArchiveList::vcFillGivenLength
                                                             (UIArchiveList::string2vc("rm <rowindex>,<colindex>,<num1>,<num2>...: Remove num."), 60)));
    IUI* iuiE = new UContainerVertical({iuiA, iuiD});
    IUI* iuiF = new UContainerVertical({iuiDE1, iuiDE2, iuiDE3, iuiDE4, iuiDE5});
    IUI* iuiG = new UContainerHorizontal({iuiE, iuiF});
    iuiD->setFather(iuiE);
    iuiC->setFather(iuiD);
    iuiB->setFather(iuiD);
    iuiA->setFather(iuiE);
    iuiE->setFather(iuiG);
    iuiDE1->setFather(iuiF);
    iuiDE2->setFather(iuiF);
    iuiDE3->setFather(iuiF);
    iuiDE4->setFather(iuiF);
    iuiDE5->setFather(iuiF);
    iuiF->setFather(iuiG);
    map<string, UI*> uisGame = {{"replay", iuiA}, {"save", iuiA}, {"set", iuiA}, {"rm", iuiA},
                                {"exit",   iuiC}};
    sceneGame->setUIs(uisGame);
    sceneGame->setUIRoot(iuiG);

    return sceneGame;
}