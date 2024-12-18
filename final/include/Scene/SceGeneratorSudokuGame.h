//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_SCEGENERATORSUDOKUGAME_H
#define FINAL_SCEGENERATORSUDOKUGAME_H

#include "SceGenerator.h"

class SceGeneratorSudokuGame: public SceGenerator {
public:
    virtual Scene * genScene(Application *application, SceGenerParaList *sceGenerParaList = nullptr) override;
};


#endif //FINAL_SCEGENERATORSUDOKUGAME_H
