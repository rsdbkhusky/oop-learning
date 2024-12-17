//
// Created by lenovo on 2024/11/7.
//

#include <algorithm>
#include <string>
#include <cassert>
#include "../../include/UI/UISudoku.h"
#include "../../include/Input/InputMessage.h"
#include "../../include/Logic/LogicSudoku.h"
#include "../../include/Logic/LogicCell.h"
#include "../../include/Scene/Scene.h"
#include "../../include/Application/Application.h"
#include "../../include/Data/DataManager.h"
#include "../../include/Data/DataManagerSudoku.h"
using std::copy;
using std::string;

UISudoku::UISudoku(LogicSudoku* _pLogicSudoku, Scene* _mpScene, IUI* _mpFather):
    mpLogicSudoku(_pLogicSudoku), UI(_mpScene, _mpFather) {
    mpReplayLogicSudoku = new LogicSudoku(*mpLogicSudoku);
}

const LogicSudoku& UISudoku::getLogicSudoku() const {
    return *mpLogicSudoku;
}

void UISudoku::receive(const InputMessage& inputMessage) {
    mpScene->setReDisplay(true);
    const string& name = inputMessage.getName();
    vector<int> paras = inputMessage.getParas();
    if (name == "replay") {
        delete mpLogicSudoku;
        mpLogicSudoku = new LogicSudoku(*mpReplayLogicSudoku);
    } else if (name == "save") {
        vector<vector<int>> vvi = mpLogicSudoku->getCells2VVI();
        DataManager* dataManager = mpScene->getApplication().getDataManager();
        DataManagerSudoku* dataManagerSudoku = dynamic_cast<DataManagerSudoku*>(dataManager);
        if (dataManagerSudoku == nullptr) assert(!"DataManager type error!");
        dataManagerSudoku->setSudoku(vvi);
        dataManagerSudoku->addFile();
    } else if (name == "set") {
        mpLogicSudoku->setCellNum(paras[0], paras[1], paras[2]);
    } else if (name == "rm") {
        int x = paras.front();
        paras.erase(begin(paras));
        int y = paras.front();
        paras.erase(begin(paras));
        mpLogicSudoku->removeCellCandidates(x, y, paras);
    }
}