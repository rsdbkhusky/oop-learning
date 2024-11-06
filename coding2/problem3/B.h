//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM3_B_H
#define PROBLEM3_B_H

#include <algorithm>
using std::swap;

class B {
public:
    B( ) { pch = new char; }
    ~B( ) { delete pch; }
    B& operator=(const B& rhs) {
//        if ( &rhs != this ) {
//            delete pch;
//            pch = new char(*rhs.pch);
//    }
        B temp(rhs);
        swap(temp.pch, this->pch);
        return *this;
    }
private:
    char * pch;
};

#endif //PROBLEM3_B_H
