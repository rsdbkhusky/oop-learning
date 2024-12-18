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

vector<char> UIArchiveList::string2vc(const string& str) {
    vector<char> vc;
    vc.resize(str.size());
    for (int i = 0; i < str.size(); ++i) {
        vc[i] = str[i];
    }
    return vc;
}

string UIArchiveList::vc2string(const vector<char>& vc) {
    string str;
    str.resize(vc.size());
    for (int i = 0; i < vc.size(); ++i) {
        str[i] = vc[i];
    }
    return str;
}

vector<char> UIArchiveList::vcFillGivenLength(const vector<char>& vc, int length, char ch) {
    vector<char> result = vc;
    length -= vc.size();
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
        if (i != fileCnt) mText[index++] = UIArchiveList::vcFillGivenLength({}, m, '-');
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
    LogicSudoku* logicSudoku = LogicSudoku::createLogicSudoku(3, 0.5);
    UI* iuiA = new UISudoku(logicSudoku, scene);
    UI* iuiB = new UIText("Welcome to RsdbkHusky's Sudoku!", scene);
    UI* iuiC = new UIButtonSwitchScene("MainMenu", true, false,
                                       {UIArchiveList::string2vc("exit")}, scene);
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
    scene->setUIs(uisGame);
    scene->setUIRoot(iuiG);

    return scene;
}