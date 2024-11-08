//
// Created by lenovo on 2024/11/8.
//

#ifndef FINAL_SINGLETON_H
#define FINAL_SINGLETON_H

class Singleton {
public:
    static Singleton& getInstance();
    static void destroyInstance();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
private:
    static Singleton* sInstance;
};

#endif //FINAL_SINGLETON_H
