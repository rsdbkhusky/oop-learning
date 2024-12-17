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
    UContainerHorizontal(const vector<IUI*>& _mIUIs, IUI* _mpFather = nullptr);
    virtual IUI** begin() override;
    virtual IUI** end() override;
    const vector<IUI*>& getIUIs() const;
protected:
    vector<IUI*> mIUIs;
};


#endif //FINAL_UCONTAINERHORIZONTAL_H
