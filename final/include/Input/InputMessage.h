//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_INPUTMESSAGE_H
#define FINAL_INPUTMESSAGE_H

#include <string>
#include <vector>
using std::string;
using std::vector;

enum class InputReturnValue {
    SUCCESS,
    ERROR_NOSUCHNAME, ERROR_EMPTYMESSAGE, ERROR_PARASIZECONFLICT,
};

class InputMessage {
public:
    const string& getName() const;
    void setName(const string& name);
    const vector<int>& getParas() const;
    void addPara(int para);
private:
    string mName;
    vector<int> mParas;
};


#endif //FINAL_INPUTMESSAGE_H
