//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_UCONTAINER_H
#define FINAL_UCONTAINER_H

#include "IUI.h"

class UContainer: public IUI {
public:
    UContainer(IUI* _mpFather = nullptr);
    virtual IUI** begin();
    virtual IUI** end();
};


#endif //FINAL_UCONTAINER_H
