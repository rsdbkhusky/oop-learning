//
// Created by lenovo on 2024/12/18.
//

#include "../../include/Scene/SceGeneratorSudokuGame.h"
#include "../../include/Application/Application.h"
#include "../../include/Scene/Scene.h"
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/UI/UI.h"
#include "../../include/UI/UIText.h"
#include "../../include/UI/UIButtonSwitchScene.h"
#include "../../include/UI/UIArchiveList.h"
#include "../../include/UI/UContainerVertical.h"

#include "../../include/Scene/SceGeneratorArchiveList.h"

Scene* SceGeneratorArchiveList::genScene(Application* application, SceGenerParaList* sceGenerParaList) {
    Scene* sceneArchiveList = new Scene(application);

    UI* iuiG = new UIArchiveList("Game", true, true,
                                 sceneArchiveList);
    UI* iuiG2 = new UIText("load <index>: Load the corresponding archive.", sceneArchiveList);
    IUI* iuiG3 = new UContainerVertical({iuiG, iuiG2});
    map<string, UI*> uisArchiveList = {{"load", iuiG}};
    sceneArchiveList->setUIs(uisArchiveList);
    sceneArchiveList->setUIRoot(iuiG3);

    return sceneArchiveList;
}