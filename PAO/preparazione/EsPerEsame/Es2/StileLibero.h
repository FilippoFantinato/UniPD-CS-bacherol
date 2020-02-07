//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_STILELIBERO_H
#define LIBRERIELEZIONI_STILELIBERO_H

#include "Nuoto.h"

class StileLibero: public Nuoto{
private:
public:
    virtual unsigned int calorie() const{
        return (durata()<10 ? 35 : 40)*numeroVasche();
    };
    virtual StileLibero* clone() const{
        return new StileLibero(*this);
    }
};
#endif //LIBRERIELEZIONI_STILELIBERO_H
