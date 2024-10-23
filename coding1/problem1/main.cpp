#include <iostream>
#include "MyApp.h"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    MyApp myApp;
    myApp.receiveCommand(argc, argv);
    return myApp.executeCommand();
}
