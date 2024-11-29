//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM18_PARALIST_H
#define PROBLEM18_PARALIST_H

#include <map>
#include <string>
using std::map;
using std::string;
class Object;

class ParaList {
public:
    ParaList(Object* _pObject, const map<string, void*>& _mPara);
    virtual ~ParaList();
    ParaList(const ParaList& rhs);
    ParaList& operator=(const ParaList& rhs);
    const Object& getObject() const;
    const map<string, void*>& getPara() const;
protected:
    Object* pObject;
    map<string, void*> mPara;
};


#endif //PROBLEM18_PARALIST_H
