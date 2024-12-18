//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_INPUTPROCESSOR_H
#define FINAL_INPUTPROCESSOR_H

#include <cassert>
#include <sstream>
#include <set>
#include "InputMessage.h"
using std::set;
using std::end;
using std::pair;

#include <iostream>
using std::cout;
using std::endl;

class InputProcessor {
public:
    static pair<InputReturnValue, InputMessage> string2message(const string& input) {
        InputMessage inputMessage;
        std::istringstream stream(input);
        string word;
        vector<string> words;
        while (stream >> word) {
            words.push_back(word);
        }
        if (words.empty()) return {InputReturnValue::ERROR_EMPTYMESSAGE, inputMessage};
        inputMessage.setName(words[0]);
        if (zeroOperand.find(words[0]) != end(zeroOperand)) {
            return {InputReturnValue::SUCCESS, inputMessage};
        } else if (xyzOperand.find(words[0]) != end(xyzOperand)) {
            if (words.size() != 2) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            string currentNum;
            for (char ch: words[1]) {
                if (isdigit(ch)) {
                    currentNum += ch;
                } else if (!currentNum.empty()) {
                    inputMessage.addPara(stoi(currentNum));
                    currentNum.clear();
                }
            }
            if (!currentNum.empty()) {
                inputMessage.addPara(stoi(currentNum));
            }
            if (inputMessage.getParas().size() != 3) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            return {InputReturnValue::SUCCESS, inputMessage};
        } else if (xyzlistOperand.find(words[0]) != end(xyzlistOperand)) {
            if (words.size() != 2) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            string currentNum;
            for (char ch: words[1]) {
                if (isdigit(ch)) {
                    currentNum += ch;
                } else if (!currentNum.empty()) {
                    inputMessage.addPara(stoi(currentNum));
                    currentNum.clear();
                }
            }
            if (!currentNum.empty()) {
                inputMessage.addPara(stoi(currentNum));
            }
            if (inputMessage.getParas().size() < 3) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            return {InputReturnValue::SUCCESS, inputMessage};
        } else if (oneOperand.find(words[0]) != end(oneOperand)) {
            if (words.size() != 2) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            string currentNum;
            for (char ch: words[1]) {
                if (isdigit(ch)) {
                    currentNum += ch;
                } else if (!currentNum.empty()) {
                    inputMessage.addPara(stoi(currentNum));
                    currentNum.clear();
                }
            }
            if (!currentNum.empty()) {
                inputMessage.addPara(stoi(currentNum));
            }
            if (inputMessage.getParas().size() != 1) return {InputReturnValue::ERROR_PARASIZECONFLICT, inputMessage};
            return {InputReturnValue::SUCCESS, inputMessage};
        }
        return {InputReturnValue::ERROR_NOSUCHNAME, inputMessage};
    }
private:
    static set<string> zeroOperand;
    static set<string> oneOperand;
    static set<string> xyzOperand;
    static set<string> xyzlistOperand;
};

set<string> InputProcessor::zeroOperand = {"help", "exit", "replay", "save", "enter", "archive", "random", "setting"};

set<string> InputProcessor::oneOperand = {"load"};

set<string> InputProcessor::xyzOperand = {"set"};

set<string> InputProcessor::xyzlistOperand = {"rm"};

#endif //FINAL_INPUTPROCESSOR_H
