#include <iostream>
#include "ExtString.h"
using std::cout;
using std::endl;

int main() {
    ExtString s1; 
    ExtString s2("���ִ�ѧ");
    ExtString s3( "�����ѧԺ" );

    cout << s1->size( ) << endl;
    cout << s2->size( ) << endl;
    cout << s3->size( ) << endl;

    ExtString ss = s2.concat( s3, "-" );
    cout << ss->c_str() << endl;
    s1 = "����";
    cout << s1.append( s2 )->c_str( ) << endl;
}

/*
��չ�ַ���
��ϣ������ExtString�࣬������˾���STL��string��Ĺ����⣬�������ַ���ƴ����Ϊ��
ExtString concat( const ExtString & other, const ExtString & interval ="" ) const;
ExtString & append( const ExtString & other );
�붨�岢ʵ��ExtString�ࡣ�ο��Ĳ��Դ���������£�

���:

*/