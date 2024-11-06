#include <iostream>
#include "ABC.h"

class D: public B {
public:
    D(int a, int b, int c, int d):B(a, b), mpC(new C(a, c)), mD(d) {}
    ~D() { delete mpC; }
    D(const D& rhs) {
        mpC = new C(&rhs.mpC); // 为什么C没有拷贝构造了
    }
    C* getmpC() const { return mpC; }
protected:
    C * mpC;
    int mD;
};

int main( ) {
    D d( 1, 2, 3, 4 );
    d.A::f( ); //输出1
    d.B::f( ); //输出2
    d.getmpC()->f( ); //输出3
    d.f( );  //输出4
}