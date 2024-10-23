//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM4_KEYCHAR_H
#define PROBLEM4_KEYCHAR_H

#include <string>
#include <unordered_map>

class KeyChar {
public:
    enum Value : unsigned long {
        KEY_YES = 0x1,
        KEY_NO = 0x2,
        KEY_OK = 0x4,
        KEY_CANCEL = 0x8,
        KEY_ABORT = 0x10,
        KEY_RETRY = 0x20,
        KEY_HELP = 0x40,
    };
    static const std::string& getName(Value key) {
        static std::unordered_map<Value, std::string> keyMap = {
                {KEY_YES, "Yes"},
                {KEY_NO, "No"},
                {KEY_OK, "Ok"},
                {KEY_CANCEL, "Cancel"},
                {KEY_ABORT, "Abort"},
                {KEY_RETRY, "Retry"},
                {KEY_HELP, "Help"}
        };
        return keyMap[key];
    }
};

#endif //PROBLEM4_KEYCHAR_H
