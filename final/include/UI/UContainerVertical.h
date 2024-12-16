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
    UContainerVertical(const vector<IUI*>& _mIUIs);
    const vector<IUI*>& getIUIs() const;
protected:
    vector<IUI*> mIUIs;
};


#endif //FINAL_UCONTAINERVERTICAL_H
