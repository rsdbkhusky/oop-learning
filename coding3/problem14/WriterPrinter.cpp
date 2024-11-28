//
// Created by lenovo on 2024/11/28.
//

#include "WriterPrinter.h"

const string& WriterPrinter::getstring() const {
    return mString;
}

void WriterPrinter::write(char c) {
    mString.push_back(c);
}