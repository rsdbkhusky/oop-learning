#include <iostream>
#include "Cat.h"
#include "Dog.h"
using std::cout;
using std::endl;

int main() {
    Cat c(37, 3, 1);
    Dog d(20, 2, 0);
    cout << c.fight(d) << endl;
    c = Cat(37, 3, 1);
    d = Dog(20, 2, 0);
    cout << d.fight(c) << endl;
}
