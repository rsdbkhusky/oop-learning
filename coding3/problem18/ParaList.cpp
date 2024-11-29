//
// Created by lenovo on 2024/11/29.
//

#include <algorithm>
#include "ParaList.h"
#include "Object.h"
using std::swap;

ParaList::ParaList(Object* _pObject, const map<std::string, void*>& _mPara): pObject(_pObject), mPara(_mPara) {}

ParaList::~ParaList() {
    delete pObject;
}

ParaList::ParaList(const ParaList& rhs): mPara(rhs.mPara) {
    pObject = new Object(*rhs.pObject);
}

ParaList& ParaList::operator=(const ParaList& rhs) {
    mPara = rhs.mPara;
    ParaList temp(rhs);
    swap(pObject, temp.pObject);
    return *this;
}

const Object& ParaList::getObject() const {
    return *pObject;
}

const map<string, void*>& ParaList::getPara() const {
    return mPara;
}
