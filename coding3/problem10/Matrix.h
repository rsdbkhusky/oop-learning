//
// Created by lenovo on 2024/11/27.
//

#ifndef PROBLEM10_MATRIX_H
#define PROBLEM10_MATRIX_H

#include <vector>
using std::vector;

class Item;
class Matrix {
public:
    Matrix(const vector<vector<Item*>>& _mMatrix);
    ~Matrix();
    const vector<vector<Item*>>& getMatrix() const;
    void turn();
    void transform();
protected:
    vector<vector<Item*>> mMatrix;
};


#endif //PROBLEM10_MATRIX_H
