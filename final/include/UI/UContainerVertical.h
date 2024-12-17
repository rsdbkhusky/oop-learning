//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_UCONTAINERVERTICAL_H
#define FINAL_UCONTAINERVERTICAL_H

#include <vector>
#include "UContainer.h"
using std::vector;

class UContainerVertical: public UContainer {
public:
    UContainerVertical(const vector<const IUI*>& _mIUIs, IUI* _mpFather = nullptr);
    const vector<const IUI*>& getIUIs() const;
protected:
    vector<const IUI*> mIUIs;
};


#endif //FINAL_UCONTAINERVERTICAL_H
