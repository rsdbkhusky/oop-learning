#include <iostream>
#include "ExtString.h"
using std::cout;
using std::endl;

int main() {
    ExtString s1; 
    ExtString s2("吉林大学");
    ExtString s3( "计算机学院" );

    cout << s1->size( ) << endl;
    cout << s2->size( ) << endl;
    cout << s3->size( ) << endl;

    ExtString ss = s2.concat( s3, "-" );
    cout << ss->c_str() << endl;
    s1 = "我在";
    cout << s1.append( s2 )->c_str( ) << endl;
}

/*
扩展字符串
现希望定义ExtString类，该类除了具有STL中string类的功能外，需新增字符串拼接行为：
ExtString concat( const ExtString & other, const ExtString & interval ="" ) const;
ExtString & append( const ExtString & other );
请定义并实现ExtString类。参考的测试代码可能如下：

输出:

*/