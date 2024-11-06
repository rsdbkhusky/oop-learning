#include <iostream>
#include "D.h"

int main( ) {
    D d( 1, 2, 3, 4 );
    d.A::f( ); //输出1
    d.B::f( ); //输出2
    d.C::f( ); //输出3
    d.f( );  //输出4
}