//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM19_METHODSOLVERESULT_H
#define PROBLEM19_METHODSOLVERESULT_H

class Data;

class MethodSolveResult {
public:
    virtual ~MethodSolveResult();
    virtual float solve(float result, const Data* history, int years);
};


#endif //PROBLEM19_METHODSOLVERESULT_H
