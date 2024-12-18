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
    IUI* iuiE = new UContainerVertical({iuiA, iuiD});
    iuiD->setFather(iuiE);
    iuiC->setFather(iuiD);
    iuiB->setFather(iuiD);
    iuiA->setFather(iuiE);
    map<string, UI*> uisGame = {{"replay", iuiA}, {"save", iuiA}, {"set", iuiA}, {"rm", iuiA},
                                {"exit",   iuiC}};
    sceneGame->setUIs(uisGame);
    sceneGame->setUIRoot(iuiE);

    return sceneGame;
}