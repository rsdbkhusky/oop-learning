//
// Created by lenovo on 2024/11/6.
//

#include "ExtString.h"

string *ExtString::operator->() const {
    return mString;
}

ExtString ExtString::concat(const ExtString &other, const ExtString &interval) const {
    return ExtString(*(this->mString) + *(interval.mString) + *(other.mString));
}

ExtString &ExtString::append(const ExtString &other) {
    (*(this->mString)).append(*(other.mString));
    return *this;
}