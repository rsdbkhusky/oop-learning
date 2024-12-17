//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_INPUTERRORHANDLER_H
#define FINAL_INPUTERRORHANDLER_H

#include <string>
#include "../Utils/Singleton.h"
class IUI;
using std::string;

class InputErrorHandler: public Singleton<InputErrorHandler> {
    friend class Singleton<InputErrorHandler>;
public:
    void setMessage(const string& message);
    void resetMessage();
    IUI* handleDisplayUIRoot(IUI* displayUIRoot);
protected:
    InputErrorHandler() = default;
    virtual ~InputErrorHandler() override = default;
    string mMessage;
};


#endif //FINAL_INPUTERRORHANDLER_H
