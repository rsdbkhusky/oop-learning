//
// Created by lenovo on 2024/11/28.
//

#include "VectorV2.h"

VectorV2::VectorV2(double* values): Vector(values) {}

VectorV2& VectorV2::StandardOrder1() {
    double nv = NormalValueOrder1();
    for (int i = 0; i < N; ++i)
        items[i] /= nv;
    return *this;
}

VectorV2& VectorV2::StandardOrder2() {
    double nv = NormalValueOrder2();
    for (int i = 0; i < N; ++i)
        items[i] /= nv;
    return *this;
}

VectorV2& VectorV2::StandardOrderinf() {
    double nv = NormalValueOrderinf();
    for (int i = 0; i < N; ++i)
        items[i] /= nv;
    return *this;
}

double VectorV2::NormalValueOrder1() const {
    return NormalValue(1);
}

double VectorV2::NormalValueOrder2() const {
    return NormalValue(2);
}

double VectorV2::NormalValueOrderinf() const {
    return NormalValue(0);
}
