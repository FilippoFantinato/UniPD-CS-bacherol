//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_NUOTO_H
#define LIBRERIELEZIONI_NUOTO_H

#include "Workout.h"

class Nuoto : public Workout{
private:
    unsigned int vasche;
public:
    unsigned int numeroVasche() const{
        return vasche;
    }
    Nuoto* clone() const override = 0;
};
#endif //LIBRERIELEZIONI_NUOTO_H
