//
// Created by lenovo on 2024/11/29.
//

#include "Server.h"
#include "CallBackObject.h"

int Server::Total(CallBackObject& obj) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        // TODO 3
        sum += obj.CallBackFunc(data[i]);
    }
    return sum;
}