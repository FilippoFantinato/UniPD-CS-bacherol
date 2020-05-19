//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_STILELIBERO_H
#define LIBRERIELEZIONI_STILELIBERO_H

#include "Nuoto.h"

class Dorso: public Nuoto{
private:
public:
    virtual unsigned int calorie() const{
        return (durata()<15 ? 30 : 35)*numeroVasche();
    };
    virtual Dorso* clone() const{
        return new Dorso(*this);
    }
};
#endif //LIBRERIELEZIONI_STILELIBERO_H