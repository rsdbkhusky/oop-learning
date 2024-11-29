//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM17_SERVER_H
#define PROBLEM17_SERVER_H

#include <iostream>
class CallBackObject;
class Server {
public:
    Server(int size): len(size) {
        // TODO 1
        data = new int[len];
        for (int i = 0; i < len; ++i)
            data[i] = i + 1;
    }
    ~Server() {
        // TODO 2
        delete[] data;
    }
    int Total(CallBackObject& obj);
private:
    int len;
    int* data;
};


#endif //PROBLEM17_SERVER_H
