//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM4_PROCESSSTRING_H
#define PROBLEM4_PROCESSSTRING_H

#include <string>
#include <algorithm>

using std::string;

class ProcessString {
public:
    static string toLower(const string& str) {
        string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

#endif //PROBLEM4_PROCESSSTRING_H
