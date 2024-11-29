//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM20_SYSTEM_H
#define PROBLEM20_SYSTEM_H

class StandardVideoStream;

class System {
public:
    virtual ~System() = default;
    virtual void playStandardVideoStream(const StandardVideoStream& standardVideoStream);
};


#endif //PROBLEM20_SYSTEM_H
