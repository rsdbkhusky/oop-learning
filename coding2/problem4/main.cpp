#include <iostream>
#include "Container.h"

int main( ) {
    Container vc;
    const Container cc(20);
    for(int i=0;i<3;++i)
        vc.Item(i) += i * cc.Item(i);
    for(int i=0;i<3;++i)
        std::cout<<vc.Item(i)<<' ';
    return 0;
}

/*
2. 不可以，因为有实例变量items，items是数组，本质上是指针，如果不自定义拷贝构造函数和赋值函数，而是使用缺省的，会导致浅拷贝，拷贝的和原来的对象实际上是共用一个items数组


1）请补充完善Container类的定义和实现，使得主程序输出10 30 50。
2）请回答，对于Container类，不自定义拷贝构造函数和赋值函数，而是使用缺省的，是否可以，为什么?
*/