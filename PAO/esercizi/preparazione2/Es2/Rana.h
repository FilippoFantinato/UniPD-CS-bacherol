//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_RANA_H
#define LIBRERIELEZIONI_RANA_H

#include "Nuoto.h"

class Rana: public Nuoto{
private:
public:
    virtual unsigned int calorie() const{
        return 25*numeroVasche();
    };
    virtual Rana* clone() const{
        return new Rana(*this);
    }
};
#endif //LIBRERIELEZIONI_RANA_H
