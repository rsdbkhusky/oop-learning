//
// Created by lenovo on 2024/10/18.
//

#include "CommandPara.h"

void CommandPara::setParaHead(const std::string& paraHead) {
    mParaHead = paraHead;
}
const string& CommandPara::getParaHead() const {
    return mParaHead;
}
void CommandPara::setParaData(const vector<std::string>& paraData) {
    mParaData = paraData;
}
void CommandPara::addParaData(const std::string &paraData) {
    mParaData.push_back(paraData);
}
const vector<string>& CommandPara::getParaData() const {
    return mParaData;
}
