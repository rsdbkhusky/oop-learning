#include <iostream>
#include "Cat.h"
#include "Octopus.h"
#include "Whale.h"
#include "Turtle.h"
#include "Shark.h"
using std::cout;
using std::endl;

int main() {
    Cat cat(1, 0);
    Octopus octopus(200);
    Whale whale;
    Turtle turtle;
    Shark shark(300);
    cout << cat.getExp() << ' ' << cat.getLevel() << endl;
    cat.CatchFish(octopus);
    cout << cat.getExp() << ' ' << cat.getLevel() << endl;
    cat.CatchFish(whale);
    cout << cat.getExp() << ' ' << cat.getLevel() << endl;
    cat.CatchFish(turtle);
    cout << cat.getExp() << ' ' << cat.getLevel() << endl;
    cat.CatchFish(shark);
    cout << cat.getExp() << ' ' << cat.getLevel() << endl;
}
