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
#include "include/Scene/SceGeneratorSudokuGame.h"
#include "include/Scene/SceGeneratorArchiveList.h"
#include "include/UI/UIButtonSwitchSceneGenerator.h"

int main() {
    Application* application = new Application(&InputReceiverConsole::Singleton<InputReceiverConsole>::getInstance(),
                                               &InputErrorHandler::Singleton<InputErrorHandler>::getInstance(),
                                               &OutputDisplayerConsole::Singleton<OutputDisplayerConsole>::getInstance(),
                                               &DataManagerSudoku::Singleton<DataManagerSudoku>::getInstance());
    Scene* sceneGame;
    Scene* sceneStartMenu = new Scene(application);
    Scene* sceneArchiveList;
    Scene* sceneMainMenu = new Scene(application);

    SceGeneratorSudokuGame* sceGeneratorSudokuGame = new SceGeneratorSudokuGame();
    sceneGame = sceGeneratorSudokuGame->genScene(application);

    UI* iuiF = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("enter")}, sceneStartMenu);
    UI* iuiF2 = new UIText("Enter the button name to click the corresponding button.", sceneStartMenu);
    IUI* iuiF3 = new UContainerVertical({iuiF, iuiF2});
    map<string, UI*> uisStartMenu = {{"enter", iuiF}};
    sceneStartMenu->setUIs(uisStartMenu);
    sceneStartMenu->setUIRoot(iuiF3);

    SceGeneratorArchiveList* sceGeneratorArchiveList = new SceGeneratorArchiveList();
    sceneArchiveList = sceGeneratorArchiveList->genScene(application);

    UI* iuiH = new UIButtonSwitchSceneGenerator(sceGeneratorArchiveList, "ArchiveList", false, true,
                                             {UIArchiveList::string2vc("archive")}, sceneMainMenu);
    UI* iuiI = new UIButtonSwitchSceneGenerator(sceGeneratorSudokuGame, "Game", false, true,
                                                {UIArchiveList::string2vc("random")}, sceneMainMenu);
    IUI* iuiK = new UContainerVertical({iuiH, iuiI});
    iuiH->setFather(iuiK);
    iuiI->setFather(iuiK);
    map<string, UI*> uisMainMenu = {{"archive", iuiH}, {"random", iuiI}};
    sceneMainMenu->setUIs(uisMainMenu);
    sceneMainMenu->setUIRoot(iuiK);

    map<string, Scene*> scenes = {{"StartMenu", sceneStartMenu}, {"Game", sceneGame},
                                  {"ArchiveList", sceneArchiveList}, {"MainMenu", sceneMainMenu}};

    application->setScenes(scenes);
    application->setRunningSceneName("StartMenu");

    application->init();
    application->run();
}
