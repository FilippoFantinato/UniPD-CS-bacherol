//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ES7_H
#define LIBRERIELEZIONI_ES7_H
class A{
public:
    virtual ~A() = default;
};
class B: public A{
public:
    ~B() = 0;
};
B::~B() = default;

class C: public B{};

class D{
protected:
    D() = default;
};
class E: public D{
    E& operator=(const E& e){
       D::operator=(e);
       return *this;
    }
};
#endif //LIBRERIELEZIONI_ES7_H
