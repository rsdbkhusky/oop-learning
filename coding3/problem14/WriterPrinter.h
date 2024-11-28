//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM14_WRITERPRINTER_H
#define PROBLEM14_WRITERPRINTER_H

#include <string>
#include "Writer.h"
using std::string;

class WriterPrinter: public Writer {
public:
    const string& getstring() const;
    virtual void write(char c) override;
protected:
    string mString;
};


#endif //PROBLEM14_WRITERPRINTER_H
