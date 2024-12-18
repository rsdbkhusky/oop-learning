//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_SCEGENERATORARCHIVELIST_H
#define FINAL_SCEGENERATORARCHIVELIST_H

#include "SceGenerator.h"

class SceGeneratorArchiveList: public SceGenerator {
public:
    virtual Scene * genScene(Application *application, SceGenerParaList *sceGenerParaList = nullptr) override;
};


#endif //FINAL_SCEGENERATORARCHIVELIST_H
