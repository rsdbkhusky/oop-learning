//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_IUI_H
#define FINAL_IUI_H


class IUI {
public:
    IUI(IUI* _mpFather = nullptr);
    virtual ~IUI() = default;
protected:
    IUI* mpFather;
};


#endif //FINAL_IUI_H
