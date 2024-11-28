#include <iostream>
#include "BoxMoney.h"
#include "BoxToxin.h"
#include "Solider.h"
#include "Mage.h"
using std::cout;
using std::endl;

int main() {
    Solider solider(100, 20);
    Mage mage(50, 100);
    BoxMoney boxMoney(20);
    BoxToxin boxToxin;
    cout << solider.getHp() << ' ' << solider.getMoney() << endl;
    cout << mage.getHp() << ' ' << mage.getMoney() << endl;
    solider.openBox(boxMoney);
    cout << solider.getHp() << ' ' << solider.getMoney() << endl;
    mage.openBox(boxMoney);
    cout << mage.getHp() << ' ' << mage.getMoney() << endl;
    solider.openBox(boxToxin);
    cout << solider.getHp() << ' ' << solider.getMoney() << endl;
    mage.openBox(boxToxin);
    cout << mage.getHp() << ' ' << mage.getMoney() << endl;
}
