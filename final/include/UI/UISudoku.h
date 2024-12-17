//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_UISUDOKU_H
#define FINAL_UISUDOKU_H

#include "UI.h"
class LogicSudoku;

class UISudoku: public UI {
public:
    UISudoku(LogicSudoku* _pLogicSudoku, Scene* _mpScene = nullptr, IUI* _mpFather = nullptr);
    const LogicSudoku& getLogicSudoku() const;
    virtual void receive(const InputMessage &inputMessage) override;
protected:
    LogicSudoku* mpLogicSudoku;
    LogicSudoku* mpReplayLogicSudoku;
};


#endif //FINAL_UISUDOKU_H
