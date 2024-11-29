//
// Created by lenovo on 2024/11/29.
//

#include "MyPic.h"
#include "Printer.h"
#include "Bitmap.h"

bool MyPic::SendTo(ParaList& paraList) {
    if (dynamic_cast<const Printer*>(&paraList.getObject())) {
        // ...
    } else if (dynamic_cast<const Bitmap*>(&paraList.getObject())) {
        // ...
    } else {
        // ...
    }
}