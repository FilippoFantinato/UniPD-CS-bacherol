//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_SEDEMOON_H
#define LIBRERIELEZIONI_SEDEMOON_H

#include <vector>
#include <numeric>
#include "Cliente.h"
#include "AlMinuto.h"
#include "Abbonamento.h"

class SedeMoon{
private:
    std::vector<Cliente*> clienti;
public:
    SedeMoon() = default;
    void aggiungiCliente(const Cliente& cliente){
        clienti.push_back(cliente.clone());
    }
    double incassoMensileCorrente() const{
        auto accumulate = [&](double tot, const Cliente* c){ return tot + c->costoMeseCorrente();};
        return std::accumulate(clienti.begin(), clienti.end(), 0.0, accumulate);
    }
    int numClientiAbbonatiOltreSoglia() const{
        return std::accumulate(clienti.begin(), clienti.end(), 0, [&](int tot, const Cliente* c){
            if(auto* p = dynamic_cast<const Abbonamento*>(c); p && p->getMinuti() > p->getMaxMinuti()) return tot+1;
            else return tot;
        });
    }
    std::vector<AlMinuto> alMinutoSMS(int x){
        std::vector<AlMinuto> m;
        std::for_each(clienti.begin(), clienti.end(), [&](const Cliente* c){
            auto* p = dynamic_cast<const AlMinuto*>(c);
            if(p && p->getSms()>x) m.push_back(*(p->clone()));
        });
        return m;
    }
};
#endif //LIBRERIELEZIONI_SEDEMOON_H
