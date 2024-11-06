//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM6_ABC_H
#define PROBLEM6_ABC_H

#include <iostream>
using std::cout;
using std::endl;

class A {
public:
    A( int a ) :mA( a ) { }
    virtual ~A( ) = default;
    virtual void f( ) { cout << mA << endl; }
protected:
    int mA;
};

class B : public A {
public:
    B( int a, int b ) :A( a ), mB( b ) { }
    virtual void f( ) { cout << mB << endl; }
protected:
    int mB;
};

class C : public A {
public:
    C( int a, int c ) :A( a ), mC( c ) { }
    virtual void f( ) { cout << mC << endl; }
protected:
    int mC;
};

#endif //PROBLEM6_ABC_H
