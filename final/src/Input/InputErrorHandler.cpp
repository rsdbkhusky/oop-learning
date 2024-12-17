//
// Created by lenovo on 2024/12/16.
//

#include "../../include/Input/InputErrorHandler.h"
#include "../../include/UI/UContainerVertical.h"
#include "../../include/UI/UIText.h"

void InputErrorHandler::setMessage(const string& message) {
    mMessage = message;
}

void InputErrorHandler::resetMessage() {
    mMessage = "";
}

IUI* InputErrorHandler::handleDisplayUIRoot(const IUI* displayUIRoot) {
    if (mMessage.size() == 0) {
        return new UContainerVertical({displayUIRoot});
    } else {
        IUI* msg = new UIText(mMessage);
        IUI* result = new UContainerVertical({displayUIRoot, msg});
        return result;
    }
}