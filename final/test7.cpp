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
#include "include/Input/InputReceiverConsole2.h"
#include "include/Input/InputErrorHandler.h"
#include "include/Output/OutputDisplayerConsole.h"
#include "include/Output/OutputDisplayerConsole2.h"
#include "include/Data/DataManagerSudoku.h"
#include "include/Scene/SceGeneratorSudokuGame.h"
#include "include/Scene/SceGeneratorArchiveList.h"
#include "include/UI/UIButtonSwitchSceneGenerator.h"

int main() {
    Application* application = new Application(&InputReceiverConsole2::Singleton<InputReceiverConsole2>::getInstance(),
                                               &InputErrorHandler::Singleton<InputErrorHandler>::getInstance(),
                                               &OutputDisplayerConsole2::Singleton<OutputDisplayerConsole2>::getInstance(),
                                               &DataManagerSudoku::Singleton<DataManagerSudoku>::getInstance());
    Scene* sceneGame;
    Scene* sceneStartMenu = new Scene(application);
    Scene* sceneArchiveList;
    Scene* sceneMainMenu = new Scene(application);
    Scene* sceneSetting = new Scene(application);

    SceGeneratorSudokuGame* sceGeneratorSudokuGame = new SceGeneratorSudokuGame();
    sceneGame = sceGeneratorSudokuGame->genScene(application);

    UI* iuiF = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("enter")}, sceneStartMenu);
    map<string, UI*> uisStartMenu = {{"enter", iuiF}};
    sceneStartMenu->setUIs(uisStartMenu);
    sceneStartMenu->setUIRoot(iuiF);

    SceGeneratorArchiveList* sceGeneratorArchiveList = new SceGeneratorArchiveList();
    sceneArchiveList = sceGeneratorArchiveList->genScene(application);

    UI* iuiH = new UIButtonSwitchSceneGenerator(sceGeneratorArchiveList, "ArchiveList", false, true,
                                             {UIArchiveList::string2vc("archive")}, sceneMainMenu);
    UI* iuiI = new UIButtonSwitchSceneGenerator(sceGeneratorSudokuGame, "Game", false, true,
                                                {UIArchiveList::string2vc("random")}, sceneMainMenu);
    UI* iuiJ = new UIButtonSwitchScene("Setting", false, false,
                                       {UIArchiveList::string2vc("setting")}, sceneMainMenu);
    IUI* iuiK = new UContainerVertical({iuiH, iuiI, iuiJ});
    iuiH->setFather(iuiK);
    iuiI->setFather(iuiK);
    iuiJ->setFather(iuiK);
    map<string, UI*> uisMainMenu = {{"archive", iuiH}, {"random", iuiI}, {"setting", iuiJ}};
    sceneMainMenu->setUIs(uisMainMenu);
    sceneMainMenu->setUIRoot(iuiK);



    map<string, Scene*> scenes = {{"StartMenu", sceneStartMenu}, {"Game", sceneGame},
                                  {"ArchiveList", sceneArchiveList}, {"MainMenu", sceneMainMenu}};

    application->setScenes(scenes);
    application->setRunningSceneName("StartMenu");

//    application->run();
    application->temp_run2();
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