//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ABBONAMENTO_H
#define LIBRERIELEZIONI_ABBONAMENTO_H

#include "Cliente.h"

class Abbonamento: public Cliente{
private:
    float costo_mensile;
    unsigned int max_minuti;
public:
    Abbonamento(): costo_mensile(10.3), max_minuti(0){};
    static const float costo_chiamate_oltre_limite;
    virtual float costoMeseCorrente() const{
        return static_cast<float>(costo_mensile) + (max_minuti < getMinuti() ? static_cast<float>(getMinuti() - max_minuti ) * costo_chiamate_oltre_limite : 0) + costo_mb * static_cast<float>(getMb());
    }
    virtual Abbonamento* clone() const{
        return new Abbonamento(*this);
    }
    unsigned int getMaxMinuti() const{
        return max_minuti;
    };
};
const float Abbonamento::costo_chiamate_oltre_limite(0.3);

#endif //LIBRERIELEZIONI_ABBONAMENTO_H
