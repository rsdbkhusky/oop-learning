//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_UCONTAINERHORIZONTAL_H
#define FINAL_UCONTAINERHORIZONTAL_H

#include <vector>
#include "UContainer.h"
using std::vector;

class UContainerHorizontal: public UContainer {
public:
    UContainerHorizontal(const vector<const IUI*>& _mIUIs, IUI* _mpFather = nullptr);
    const vector<const IUI*>& getIUIs() const;
protected:
    vector<const IUI*> mIUIs;
};


#endif //FINAL_UCONTAINERHORIZONTAL_H
