//
// Created by lenovo on 2024/10/22.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Input.h"
#include "ProcessString.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

unsigned long Input::getRangeULong(unsigned long min, unsigned long max) {
    int x;
    cin >> x;
    assert(x >= min && x <= max);
    return x;
}
KeyChar::Value Input::getKeyChar(unsigned long flags, bool caseSensitive) {
    std::unordered_map<KeyChar::Value, std::string> keyMap = {
            {KeyChar::KEY_YES, "Yes"},
            {KeyChar::KEY_NO, "No"},
            {KeyChar::KEY_OK, "Ok"},
            {KeyChar::KEY_CANCEL, "Cancel"},
            {KeyChar::KEY_ABORT, "Abort"},
            {KeyChar::KEY_RETRY, "Retry"},
            {KeyChar::KEY_HELP, "Help"}
    };

    // 逐行等待用户输入，直到输入匹配
    string input;
    while (true) {
        cin >> input;

        // 如果不区分大小写，则将输入转换为小写
        if (!caseSensitive) {
            input = ProcessString::toLower(input);
        }

        // 遍历所有的键值对，匹配 flags 中的标志
        for (const auto& entry : keyMap) {
            KeyChar::Value key = entry.first;
            string keyName = entry.second;

            // 判断当前键值是否包含在 flags 中
            if (flags & key) {
                // 如果不区分大小写，则将 keyName 转换为小写
                if (!caseSensitive) {
                    keyName = ProcessString::toLower(keyName);
                }

                // 判断输入是否是 keyName 的前缀
                if (keyName.find(input) == 0) {
                    return key; // 匹配成功，返回对应的 KeyChar::Value
                }
            }
        }

        // 如果没有匹配，提示用户重新输入
    }
}