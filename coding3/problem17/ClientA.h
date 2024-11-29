//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM17_CLIENTA_H
#define PROBLEM17_CLIENTA_H

#include <iostream>
#include "CallBackObject.h"
#include "Server.h"
using std::cout;
using std::endl;

class ClientA: public CallBackObject {
public:
    virtual ~ClientA() {}
    virtual int CallBackFunc(int val) {
        return val;
    }
    void RequestA(Server& srv) {
        // TODO 5 cout << << endl;
        cout << srv.Total(*this) << endl;
    }
};


#endif //PROBLEM17_CLIENTA_H
