//
// Created by lenovo on 2024/10/22.
//

#ifndef PROBLEM4_SINGLETON_H
#define PROBLEM4_SINGLETON_H

#include <memory>

template <typename T>
class Singleton {
public:
    static T & getInstance( ) {
        static std::shared_ptr<T> instance( new T( ) );
        return *instance;
    }
protected:
    Singleton( ) = default;
    Singleton( const Singleton & ) = delete;
    Singleton( Singleton && ) = delete;
    Singleton & operator=( const Singleton & ) = delete;
};

#endif //PROBLEM4_SINGLETON_H
