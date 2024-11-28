//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM15_VECTOR_H
#define PROBLEM15_VECTOR_H

#include <algorithm>
#include <math.h>
using std::max;
const int N = 3;

class Vector {
public:
    Vector(double values[N]) {
        for (int i = 0; i < N; ++i)
            items[i] = values[i];
    }
    double Item(int index) const {
        return items[index];
    }
    Vector& Standard(int order) {
        double nv = NormalValue(order);
        for (int i = 0; i < N; ++i)
            items[i] /= nv;
        return *this;
    }
    double NormalValue(int order) const {
        if (order <= 0) {
            double result = 0.0;
            for (int i = 0; i < N; ++i)
                result = max(result, fabs(items[i]));
            return result;
        } else {
            double sum = 0.0;
            for (int i = 0; i < N; ++i)
                sum += pow(fabs(items[i]), order);
            return pow(sum / N, 1.0 / order);
        }
    }
protected:
    double items[N];
};


#endif //PROBLEM15_VECTOR_H
