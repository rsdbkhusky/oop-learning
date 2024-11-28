#include <iostream>
#include "VectorV2.h"
using std::cout;
using std::endl;

int main() {
    double values[] = {1, 2, 3};
    VectorV2 vectorV2(values);
    cout << vectorV2.NormalValueOrder1() << endl;
    vectorV2.StandardOrder2();
    cout << vectorV2.Item(0) << ' ' << vectorV2.Item(1) << ' ' << vectorV2.Item(2) << endl;
}
