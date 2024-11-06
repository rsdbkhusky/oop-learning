//
// Created by lenovo on 2024/11/6.
//

#ifndef PROBLEM4_CONTAINER_H
#define PROBLEM4_CONTAINER_H

class Container {
public:
    Container(int defVal=10);
    int& Item(int index);
    const int& Item(int index) const;
private:
    int items[3];
};

#endif //PROBLEM4_CONTAINER_H
