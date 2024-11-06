//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM7_EXTSTRING_H
#define PROBLEM7_EXTSTRING_H

#include <string>
using std::string;

class ExtString {
public:
    ExtString(): mString(new string("")) {}
    ExtString(char* const str): mString(new string(str)) {}
    ExtString(string str): mString(new string(str)) {}
    ExtString(const ExtString& rhs): mString(new string(rhs->c_str())) {}
    string* operator->() const;
    ExtString concat( const ExtString & other, const ExtString & interval = "" ) const;
    ExtString & append( const ExtString & other );
private:
    string* mString;
};

#endif //PROBLEM7_EXTSTRING_H
