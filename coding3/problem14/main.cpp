#include <iostream>
#include "ReaderKeyboard.h"
#include "WriterPrinter.h"
#include "Copier.h"
using std::cout;

int main() {
    ReaderKeyboard readerKeyboard;
    WriterPrinter writerPrinter;
    Copier copier(&readerKeyboard, &writerPrinter);
    copier.copy();
    cout << "#" << writerPrinter.getstring() << "#";
}
