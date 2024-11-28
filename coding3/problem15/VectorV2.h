//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM15_VECTORV2_H
#define PROBLEM15_VECTORV2_H

#include "Vector.h"

class VectorV2: public Vector {
public:
    VectorV2(double values[N]);
    VectorV2& StandardOrder1();
    VectorV2& StandardOrder2();
    VectorV2& StandardOrderinf();
    double NormalValueOrder1() const;
    double NormalValueOrder2() const;
    double NormalValueOrderinf() const;
};


#endif //PROBLEM15_VECTORV2_H
