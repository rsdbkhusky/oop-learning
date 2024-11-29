//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM17_CLIENTB_H
#define PROBLEM17_CLIENTB_H


#include <iostream>
#include "CallBackObject.h"
#include "Server.h"
using std::cout;
using std::endl;

class ClientB: public CallBackObject {
public:
    virtual ~ClientB() {}
    virtual int CallBackFunc(int val) {
        // TODO 6
//        return val * val;
        cout << val << ' ';
        return val * val * val;
    }
    void RequestB(Server& srv) {
        // TODO 7
//        cout << "平方和=" << srv.Total(*this) << endl;
        int ans = srv.Total(*this);
        cout << "的立方和=" << ans << endl;
    }
};

#endif //PROBLEM17_CLIENTB_H
