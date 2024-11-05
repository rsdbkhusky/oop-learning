#include "Date.h"

int main( ) {
    Date today(2020,3,31);
    today.print( );
    today.plusMonths(1);
    today.print( );
    today.plusDays(1);
    today.print( );
}

/*
请完成Date的定义和实现（其它成员任意），使得下列主程序的输出：
2020-3-31
2020-4-30
2020-5-1
*/

