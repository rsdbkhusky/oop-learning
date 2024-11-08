#include <iostream>
#include "ABC.h"
using std::swap;

class D: public B {
public:
    D(int a, int b, int c, int d):B(a, b), mpC(new C(a, c)), mD(d) {}
    ~D() { delete mpC; }
    D(const D& rhs): B(rhs), mpC(new C(*rhs.mpC)), mD(rhs.mD) {}
    D& operator=(const D& rhs) {
        B::operator=(rhs);
        D temp(rhs);
        swap(mpC, temp.mpC);
        mD = rhs.mD;
        return *this;
    }
    C* getmpC() const { return mpC; }
    virtual void f( ) { cout << mD << endl; }
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

    // 验证可以使用拷贝、赋值
    D d2(d);
    d2.A::f( ); //输出1
    d2.B::f( ); //输出2
    d2.getmpC()->f( ); //输出3
    d2.f( );  //输出4

    D d3(5, 6, 7, 8);
    d2 = d3;
    d2.A::f( ); //输出1
    d2.B::f( ); //输出2
    d2.getmpC()->f( ); //输出3
    d2.f( );  //输出4
}