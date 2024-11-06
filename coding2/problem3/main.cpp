#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
在自定义赋值函数时，通常需要自赋值检查，但实际上这种方式，在多线程下，不是线程安全的。
因此，定义赋值函数，C++标准，建议使用swap系统函数，因为swap函数总是线程安全的。
例如：
class A
{
public:
      ...
      A & operator=(const A& rhs) {
             swap(T(rhs.mT),mT);
             return *this;
      }
private:
      T   mT;
};

1. 请说明swap(T(rhs.mT),mT);语句的执行过程和含义。
2. 请用swap函数重新实现下面代码中的赋值函数
class B {
public:
       B( )  {    pch = new char;      }
       ~B( ) {  delete pch;          }
       B& operator=(const B& rhs) {
            if ( &rhs != this )  {
                delete pch;
                pch = new char(*rhs.pch);
            }
            return *this;
        }
private:
       char * pch;
};
*/