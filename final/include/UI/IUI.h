//
// Created by lenovo on 2024/12/16.
//

#ifndef FINAL_IUI_H
#define FINAL_IUI_H


class IUI {
public:
    IUI(IUI* _mpFather = nullptr);
    virtual ~IUI() = default;
    void setFather(IUI* iui);
    IUI* getFather();
protected:
    IUI* mpFather;
};


#endif //FINAL_IUI_H
