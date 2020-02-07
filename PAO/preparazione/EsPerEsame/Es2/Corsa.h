//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_CORSA_H
#define LIBRERIELEZIONI_CORSA_H

#include "Workout.h"

class Corsa : public Workout{
private:
    float km;
public:
    virtual unsigned int calorie() const{
        return km*km / durata();
    }
    virtual Corsa* clone() const{
        return new Corsa(*this);
    }
};
#endif //LIBRERIELEZIONI_CORSA_H
