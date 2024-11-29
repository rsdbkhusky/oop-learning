#include <iostream>
#include "Bank.h"
#include "Enterprise.h"
using std::cout;
using std::endl;

int main() {
    Enterprise ent;
    Bank bank(1, 2);
    cout << bank.Evaluate(ent) << endl;
}

/*
说明设计方案：
将代码块B封装为类，并使用静态成员函数作为代码块的内容，传参为vector<int>、Bank和Enterprise，均使用引用，用于代码块内调用，并且将CodeBlockB作为Bank的友元类，使得其能向原先一样随意访问Bank类的成员，返回值也为vector<int>
*/