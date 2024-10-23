//
// Created by lenovo on 2024/10/18.
//

#ifndef CODING1_COMMANDPARA_H
#define CODING1_COMMANDPARA_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class CommandPara {
public:
    void setParaHead(const string& paraHead);
    [[nodiscard]] const string& getParaHead() const;
    void setParaData(const vector<string>& paraData);
    void addParaData(const string& paraData);
    [[nodiscard]] const vector<string>& getParaData() const;
private:
    string mParaHead;
    vector<string> mParaData;
};

#endif //CODING1_COMMANDPARA_H
