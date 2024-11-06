#include <iostream>
#include "Utility.h"
using namespace std;

int main( ) {
    cout<<Utility::countBits1(3)<<endl;
    cout<<Utility::countBits0(3)<<endl;
    cout<<Utility::countBits1(-1)<<endl;
    cout<<Utility::countBits0(-1)<<endl;
}

/*
在现代程序设计中，一般不再使用全局变量和全局函数，而是通常采用类方法和类变量的形式取代。
例如有下面的主程序：
可在32位平台下，输出整数的二进制表示中，1和0的位数：
2
30
32
0
请完成Utility类的定义和实现。
*/