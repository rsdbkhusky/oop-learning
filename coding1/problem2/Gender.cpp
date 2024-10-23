//
// Created by lenovo on 2024/10/22.
//

#include "Gender.h"
const map<Lang, string> Gender::sGenderStringInLang[2] = {
    {
        {Lang::CHN, "男"},
        {Lang::ENG, "Male"},
        {Lang::FRA, "Mâle"},
        {Lang::GER, "männlich"},
    },
    {
        {Lang::CHN, "女"},
        {Lang::ENG, "Female"},
        {Lang::FRA, "Femelle"},
        {Lang::GER, "weiblich"},
    },
};
Gender Gender::MALE = Gender(false);
Gender Gender::FEMALE = Gender(true);
bool operator==(const Gender& lhs, const Gender& rhs) {
    if (lhs.mGender == rhs.mGender) return true;
    else return false;
}
bool operator!=(const Gender& lhs, const Gender& rhs) {
    return !(lhs == rhs);
}
Gender::Gender(bool _mGender):mGender(_mGender) {}
string Gender::toString(const Lang &lang) const {
    return sGenderStringInLang[mGender].at(lang);
}