//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ES1_H
#define LIBRERIELEZIONI_ES1_H
#include <iostream>
using namespace std;
class C {
public:
    int* p;
    C(): p(new int(5)) {}
};

template<class T>
class SmartP{
private:
    T* ptr;
public:
    SmartP(): ptr(nullptr){};
    SmartP(const SmartP& p): ptr(new T(*(p.ptr))){};
    SmartP(const T* t): ptr(new T(*t)){};
    ~SmartP(){
        delete ptr;
    }
    SmartP& operator=(const SmartP& s){
        delete ptr;
        ptr = new T(*s.ptr);
        return *this;
    }
    T& operator*(){
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }
    bool operator==(const SmartP s) const{
        return *ptr == *s.ptr;
    }
    bool operator!= (const SmartP& s)const {
        return ! (*this == s);
    }
};
#endif //LIBRERIELEZIONI_ES1_H
