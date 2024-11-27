#include <iostream>
#include "Matrix.h"
#include "Int.h"
using std::cout;
using std::endl;

int main() {
    Matrix matrix({{new Int(1), new Int(2)}, {new Int(3), new Int(4)}});
    matrix.turn();
    matrix.transform();
    const vector<vector<Item*>>& mt = matrix.getMatrix();
    for (int i = 0; i < mt.size(); ++i) {
        for (int j = 0; j < mt.size(); ++j) {
            Int* num = (Int*)mt[i][j];
            cout << num->getInt() << ' ';
        }
        cout << endl;
    }
}
