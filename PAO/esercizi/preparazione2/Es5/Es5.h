//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ES5_H
#define LIBRERIELEZIONI_ES5_H
#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class B {public: virtual ~B() {} };
class C: public B {};
class D: public B {};
class E: public C {};
int Fun(vector<B*> &v){
    if(v.empty()) return 0;
    int i = 0;
    for(auto it = v.begin()+1; it!= v.end() ; ++it){
        if(dynamic_cast<C*>(*it) && typeid(**it)!= typeid(C) && typeid(**it) != typeid(*v[0])) ++i;
    }
    return i;
}
#endif //LIBRERIELEZIONI_ES5_H
