//
// Created by lenovo on 2024/12/17.
//

#include "include/Application/Application.h"
#include "include/Scene/Scene.h"
#include "include/UI/UI.h"
#include "include/UI/UISudoku.h"
#include "include/UI/UIText.h"
#include "include/UI/UIButtonSwitchScene.h"
#include "include/UI/UIArchiveList.h"
#include "include/Logic/LogicSudoku.h"
#include "include/UI/UContainerVertical.h"
#include "include/UI/UContainerHorizontal.h"
#include "include/Input/InputReceiverConsole.h"
#include "include/Input/InputErrorHandler.h"
#include "include/Output/OutputDisplayerConsole.h"
#include "include/Data/DataManagerSudoku.h"

int main() {
    Application* application = new Application(&InputReceiverConsole::Singleton<InputReceiverConsole>::getInstance(),
                                               &InputErrorHandler::Singleton<InputErrorHandler>::getInstance(),
                                               &OutputDisplayerConsole::Singleton<OutputDisplayerConsole>::getInstance(),
                                               &DataManagerSudoku::Singleton<DataManagerSudoku>::getInstance());
    Scene* scene1 = new Scene(application);
    Scene* scene2 = new Scene(application);

    LogicSudoku* logicSudoku = LogicSudoku::createLogicSudoku(3, 0.5);
    UI* iuiA = new UISudoku(logicSudoku, scene1);
    UI* iuiB = new UIText("Welcome to RsdbkHusky's Sudoku!", scene1);
    UI* iuiC = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("Exit")}, scene1);
    IUI* iuiD = new UContainerHorizontal({iuiB, iuiC});
    IUI* iuiE = new UContainerVertical({iuiA, iuiD});
    iuiD->setFather(iuiE);
    iuiC->setFather(iuiD);
    iuiB->setFather(iuiD);
    iuiA->setFather(iuiE);
    map<string, UI*> uis1 = {{"replay", iuiA}, {"save", iuiA}, {"set", iuiA}, {"rm", iuiA},
                             {"exit", iuiC}};
    UI* iuiF = new UIButtonSwitchScene("Game", false, true,
                                       {UIArchiveList::string2vc("Enter")}, scene2);
    map<string, UI*> uis2 = {{"enter", iuiF}};

    scene1->setUIs(uis1);
    scene1->setUIRoot(iuiE);
    scene2->setUIs(uis2);
    scene2->setUIRoot(iuiF);

    map<string, Scene*> scenes = {{"MainMenu", scene2}, {"Game", scene1}};

    application->setScenes(scenes);
    application->setRunningSceneName("MainMenu");

    application->run();
}

//int main() {
//    LogicSudoku* logicSudoku = LogicSudoku::createLogicSudoku(3, 0.5);
//    UI* iuiA = new UISudoku(logicSudoku);
//    UI* iuiB = new UIText("Welcome to RsdbkHusky's Sudoku!");
//    UI* iuiC = new UIButtonSwitchScene("MainMenu", true, false, {UIArchiveList::string2vc("Exit")});
//    IUI* iuiD = new UContainerHorizontal({iuiB, iuiC});
//    IUI* iuiE = new UContainerVertical({iuiA, iuiD});
//    iuiD->setFather(iuiE);
//    iuiC->setFather(iuiD);
//    iuiB->setFather(iuiD);
//    iuiA->setFather(iuiE);
//    map<string, UI*> uis1 = {{"replay", iuiA}, {"save", iuiA}, {"set", iuiA}, {"rm", iuiA},
//                             {"exit", iuiC}};
//    Scene* scene1 = new Scene(nullptr, uis1, iuiE);
//    UI* iuiF = new UIButtonSwitchScene("Game", false, true, {UIArchiveList::string2vc("Enter")});
//    map<string, UI*> uis2 = {{"enter", iuiF}};
//    Scene* scene2 = new Scene(nullptr, uis2, iuiF);
//    map<string, Scene*> scenes = {{"MainMenu", scene2}, {"Game", scene1}};
//    Application* application = new Application(&InputReceiverConsole::Singleton<InputReceiverConsole>::getInstance(),
//                                               &InputErrorHandler::Singleton<InputErrorHandler>::getInstance(),
//                                               &OutputDisplayerConsole::Singleton<OutputDisplayerConsole>::getInstance(),
//                                               &DataManagerSudoku::Singleton<DataManagerSudoku>::getInstance(),
//                                               scenes, "MainMenu");
//}