#include <iostream>
#include "MyPic.h"
#include "ParaList.h"
#include "Printer.h"
#include "Bitmap.h"

int main() {
    map<string, void*> mp;
    ParaList paraList(new Printer, mp);
}

/*
第二问：
创建ParaList时，在mPara这个map中创建新的元素，键值表示新选项的名字，权值代表指针指向这个选项的具体值（void*可兼容各种类型）
第三问：
如果有新的设备，这个设备也会是Object基类的派生类，只需要创建ParaList时，new一个相应设备的类出来传给pObject即可
*/