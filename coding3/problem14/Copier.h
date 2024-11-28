//
// Created by lenovo on 2024/11/28.
//

#ifndef PROBLEM14_COPIER_H
#define PROBLEM14_COPIER_H


class Reader;
class Writer;

class Copier {
public:
    Copier(Reader* _pReader, Writer* _pWriter);
    void copy();
private:
    Reader* pReader;
    Writer* pWriter;
};


#endif //PROBLEM14_COPIER_H
