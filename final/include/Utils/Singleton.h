//
// Created by lenovo on 2024/11/8.
//

#ifndef FINAL_SINGLETON_H
#define FINAL_SINGLETON_H

template <typename T>
class Singleton {
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

#endif //FINAL_SINGLETON_H
