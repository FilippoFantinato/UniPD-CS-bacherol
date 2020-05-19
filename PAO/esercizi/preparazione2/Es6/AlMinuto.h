//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ALMINUTO_H
#define LIBRERIELEZIONI_ALMINUTO_H

#include "Cliente.h"

class AlMinuto: public Cliente{
public:
    static const float scatto_alla_risposta, costo_telefonate_al_minuto, costo_sms;
    virtual float costoMeseCorrente() const{
        return static_cast<float>(Cliente::getChiamate())*scatto_alla_risposta + static_cast<float>(Cliente::getMb())*costo_mb + static_cast<float>(Cliente::getMinuti()) * costo_telefonate_al_minuto + static_cast<float>(Cliente::getSms()) * costo_sms;
    }
    virtual AlMinuto* clone() const{
        return new AlMinuto(*this);
    }
};
const float AlMinuto::scatto_alla_risposta(0.15);
const float AlMinuto::costo_telefonate_al_minuto(0.2);
const float AlMinuto::costo_sms(0.1);


#endif //LIBRERIELEZIONI_ALMINUTO_H
