//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM2_GENDER_H
#define PROBLEM2_GENDER_H

#include <string>
#include <map>
#include "Lang.h"
using std::string;
using std::map;

class Gender {
    friend bool operator==(const Gender &lhs, const Gender &rhs);
    friend bool operator!=(const Gender &lhs, const Gender &rhs);
public:
    static Gender MALE;
    static Gender FEMALE;
    explicit Gender(bool _mGender);
    string toString(const Lang& lang) const;
private:
    bool mGender; // 0: male, 1: female
    static const map<Lang, string> sGenderStringInLang[2];
};

#endif //PROBLEM2_GENDER_H
