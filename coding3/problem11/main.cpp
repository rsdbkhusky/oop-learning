#include <iostream>
#include "Department.h"
#include "Stuff.h"
#include "Manager.h"

int main() {
    Manager manager1(8000);
    Stuff stuff1(5000);
    Stuff stuff2(4000);
    Department department(300000);
    department.SetEmployee(&manager1, 0);
    department.SetEmployee(&stuff1, 1);
    department.SetEmployee(&stuff2, 2);
    department.ShowEachAward();
}
