//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ES4_H
#define LIBRERIELEZIONI_ES4_H

#include <typeinfo>
class Abs{
public:
    virtual ~Abs()=0;
};
Abs::~Abs(){}
class B: public Abs{};
class C{};
class D: public C{};

template<class T1, class T2>
bool Fun(T1* t1, T2& t2){
    return typeid(T1)==typeid(T2) && typeid(*t1)== typeid(t2) && dynamic_cast<Abs*>(t1);
}
#endif //LIBRERIELEZIONI_ES4_H
