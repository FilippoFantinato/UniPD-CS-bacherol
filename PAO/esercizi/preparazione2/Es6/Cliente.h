//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_CLIENTE_H
#define LIBRERIELEZIONI_CLIENTE_H

#include <iostream>

class Cliente{
private:
    unsigned int minuti, chiamate, sms, mb;

public:
    static const float costo_mb;
    Cliente(): minuti(10), chiamate(0), sms(10), mb(0){};
    virtual float costoMeseCorrente() const = 0;
    virtual Cliente* clone() const = 0;
    unsigned int getMinuti() const {
        return minuti;
    }

    unsigned int getChiamate() const {
        return chiamate;
    }

    unsigned int getSms() const {
        return sms;
    }

    unsigned int getMb() const {
        return mb;
    }
    virtual ~Cliente() = default;
};
const float Cliente::costo_mb(0.01);
#endif //LIBRERIELEZIONI_CLIENTE_H
