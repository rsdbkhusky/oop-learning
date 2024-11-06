#include <iostream>
#include "ABC.h"

class D: public B, public C {
public:
    D(int a, int b, int c, int d): B(a, b), C(a, c), mD(d) {}
    virtual void f( ) { cout << mD << endl; }
protected:
    int mD;
};

int main( ) {
    D d( 1, 2, 3, 4 );
    d.A::f( ); //输出1
    d.B::f( ); //输出2
    d.C::f( ); //输出3
    d.f( );  //输出4
}