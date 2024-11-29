#include <iostream>
#include "Server.h"
#include "ClientA.h"
#include "ClientB.h"

void main1() {
    Server srv2(2), srv5(5);
    ClientA a;
    a.RequestA(srv2);
    a.RequestA(srv5);
}

void main2() {
    Server srv2(2), srv3(3);
    ClientB b;
    b.RequestB(srv2);
    b.RequestB(srv3);
}

int main() {
    main1();
    main2();
}

/*
第一题：
1: data = new int[len];
2: delete[] data;
3: sum += obj.CallBackFunc(data[i]);
4: virtual int CallBackFunc(int val) { return 0; }
5: cout << srv.Total(*this) << endl;
第二题：
6: return val * val;
7: cout << "平方和=" << srv.Total(*this) << endl;
第三题：
6: cout << val << ' ';
   return val * val * val;
7: int ans = srv.Total(*this);
   cout << "的立方和=" << ans << endl;
*/