//
// Created by lenovo on 2024/11/27.
//

#include <algorithm>
#include "Matrix.h"
#include "Item.h"
using std::swap;

Matrix::Matrix(const vector<vector<Item*>>& _mMatrix): mMatrix(_mMatrix) {}

Matrix::~Matrix() {
    for (int i = 0; i < mMatrix.size(); ++i) {
        for (int j = 0; j < mMatrix.size(); ++j) {
            delete mMatrix[i][j];
        }
    }
}

const vector<vector<Item*>>& Matrix::getMatrix() const {
    return mMatrix;
}

void Matrix::turn() {
    for (int i = 0; i < mMatrix.size(); ++i) {
        for (int j = i + 1; j < mMatrix.size(); ++j) {
            swap(mMatrix[i][j], mMatrix[j][i]);
        }
    }
}

void Matrix::transform() {
    for (int i = 0; i < mMatrix.size(); ++i) {
        for (int j = 0; j < mMatrix.size(); ++j) {
            mMatrix[i][j]->transform();
        }
    }
}