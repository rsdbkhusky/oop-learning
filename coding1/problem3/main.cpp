#include <iostream>
#include "NumArray.h"
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main( )  {
    cout << boolalpha;
    ///以下输出语句的目标结果都应该是true/True/TRUE
    NumArray  na2(2);
    cout << (na2.head( ).val( ) == 1) << endl;
    cout << (na2.head( ).prev( ).val( ) == 1) << endl;
    cout << (na2.head( ).next( ).val( ) == 2) << endl;
    cout << (na2.tail( ).val( ) == 2) << endl;
    cout << (na2.tail( ).prev( ).val( ) == 1) << endl;
    cout << (na2.tail( ).next( ).val( ) == 2) << endl;
    NumArray  na3(3);
    cout << (na3.head( ).next( ).set(8).next( ).set(9).val( ) == 9) << endl;
    cout << (na3.prev( ).val( ) == 8) << endl;
    cout << (na3.tail( ).prev( ).val( ) == 8) << endl;
    cin.get( ); //暂停执行，保证屏幕显示内容
    return 0;
}