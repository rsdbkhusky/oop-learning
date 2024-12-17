//
// Created by lenovo on 2024/12/17.
//

#include <algorithm>
#include <cassert>
#include "../../include/UI/UIArchiveList.h"
#include "../../include/Scene/Scene.h"
#include "../../include/Application/Application.h"
#include "../../include/Data/DataManagerSudoku.h"
#include "../../include/Input/InputMessage.h"
#include "../../include/UI/UISudoku.h"
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/UI/UIText.h"
#include "../../include/UI/UContainerVertical.h"
#include "../../include/UI/UContainerHorizontal.h"
using std::max;
using std::to_string;

vector<char> UIArchiveList::string2vc(const std::string& str) {
    vector<char> vc;
    vc.resize(str.size());
    for (int i = 0; i < str.size(); ++i) {
        vc[i] = str[i];
    }
    return vc;
}

vector<char> UIArchiveList::vcFillGivenLength(const vector<char>& vc, int length, char ch) {
    vector<char> result = vc;
    while (length--) {
        result.push_back(ch);
    }
    return result;
}

UIArchiveList::UIArchiveList
    (const string& _mSwitchSceneName, bool _mDeleteCurrent, bool _mCreateNew, Scene* _mpScene, IUI* _mpFather):
     UIButtonSwitchScene(_mSwitchSceneName, _mDeleteCurrent, _mCreateNew,
                         {}, _mpScene, _mpFather) {
    DataManager* dataManager = mpScene->getApplication().getDataManager();
    dataManager->loadFileList();
    auto fileCnt = dataManager->getCntFile();
    auto fileList = dataManager->getFileList();
    int n = fileCnt * 2 - 1;
    int m = 0;
    int i = 0;
    for (auto& file: fileList) {
        ++i;
        m = max(m, (int)(to_string(i) + ". " + file).size());
    }
    mText.resize(n);
    int index = 0;
    i = 0;
    for (auto& file: fileList) {
        ++i;
        mText[index++] = UIArchiveList::vcFillGivenLength(UIArchiveList::string2vc(to_string(i) + ". " + file), m);
        mText[index++] = UIArchiveList::vcFillGivenLength({}, m, '-');
    }
}

Scene* UIArchiveList::createNewScene(const InputMessage& inputMessage) {
    Scene* scene = new Scene(&(mpScene->getApplication()));
    DataManagerSudoku* dataManagerSudoku = dynamic_cast<DataManagerSudoku*>(mpScene->getApplication().getDataManager());
    int index = inputMessage.getParas()[0];
    assert(index >= 1 && index <= dataManagerSudoku->getCntFile());
    auto file = begin(dataManagerSudoku->getFileList());
    while (--index) ++file;
    dataManagerSudoku->loadFile(*file);
    LogicSudoku* logicSudoku = LogicSudoku::createLogicSudoku(dataManagerSudoku->getSudoku());
    UI* iuiA = new UISudoku(logicSudoku, scene);
    UI* iuiB = new UIText("Welcome to RsdbkHusky's Sudoku!", scene);
    UI* iuiC = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("Exit")}, scene);
    IUI* iuiD = new UContainerHorizontal({iuiB, iuiC});
    IUI* iuiE = new UContainerVertical({iuiA, iuiD});
    iuiD->setFather(iuiE);
    iuiC->setFather(iuiD);
    iuiB->setFather(iuiD);
    iuiA->setFather(iuiE);
    map<string, UI*> uis1 = {{"replay", iuiA}, {"save", iuiA}, {"set", iuiA}, {"rm", iuiA},
                             {"exit", iuiC}};
    scene->setUIs(uis1);
    scene->setUIRoot(iuiE);
    return scene;
}