//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_INFORMA_H
#define LIBRERIELEZIONI_INFORMA_H

#include <vector>
#include "Workout.h"
#include "Nuoto.h"
#include "Rana.h"

class InForma{
private:
    std::vector<const Workout*> vector;
public:
    std::vector<Nuoto*> vasche(int vasche) const{
        std::vector<Nuoto*> v;
        for(const auto* el : vector){
            const auto* p = dynamic_cast<const Nuoto*>(el);
            if(p && p->numeroVasche() > vasche) v.push_back(p->clone());
        }
        return v;
    }
    std::vector<Workout*> calorie(int calorie) const{
        std::vector<Workout*> v;
        for(const auto* el: vector){
            if(el->calorie() > calorie && !dynamic_cast<const Rana*>(el)) v.push_back(el->clone());
        }
        return v;
    }
    void removeNuoto(){
        unsigned int max = 0;
        for(const auto* el : vector) if(dynamic_cast<const Nuoto*>(el) && el->calorie()>max) max = el->calorie();
        for(auto it = vector.begin(); it<vector.end(); ++it) {
            const auto* p = dynamic_cast<const Nuoto*>(*it);
            delete *it;
            if(p && p->calorie() == max) vector.erase(it);
        }
    }

};
#endif //LIBRERIELEZIONI_INFORMA_H
