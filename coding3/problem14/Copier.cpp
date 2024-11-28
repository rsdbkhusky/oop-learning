//
// Created by lenovo on 2024/11/28.
//

#include <cstdio>
#include "Copier.h"
#include "Reader.h"
#include "Writer.h"

Copier::Copier(Reader* _pReader, Writer* _pWriter): pReader(_pReader), pWriter(_pWriter) {}

void Copier::copy() {
    char c;
    while ((c = pReader->read()) != EOF) pWriter->write(c);
}