-- 1. Media Prenotazioni
-- Scarto quadratico medio della distribuzione delle prenotazioni nei mesi.
-- I tavoli della sede che ha ricevuto più ordinazioni.

-- Codice, nome e tipo delle merci utilizzata dalla sede che ha avuto più prenotazioni, in ordine crescente di utilizzo

-- //codice ed indirizzo delle sedi che hanno più prenotazioni nel periodo di Natale
-- 2. Bilancio totale per sede
-- Query che restituisce, per ogni sede,  il totale netto e lordo delle fatture, delle ricevute, degli stipendi e degli esborsi pagati, e non, annuale
-- 3. Merci
-- Nome e tipologia delle merci per le quali sono stati emessi più esborsi o per le quali il numero di carichi supera del 30% (oppure è il doppio) quello degli scarichi, e sedi che si sono macchiate di tale vergogna.
-- 4. Fatture emesse ad Agenzia
-- Nomi delle agenzie, codice ed indirizzo delle sedi relative, per le quali la somma degli importi delle fatture relative è superiore a quella di tutte le altre agenzie, per quella sede.

-- Le fatture emesse  all’agenzia che ha effettuato nell’arco dell’ultimo anno in media più prenotazioni

-- Nomi e cognomi dei clienti singoli che hanno effettuato una prenotazione per numero di persone superiore a quello di una prenotazione di un’agenzia nella stessa sede, se esistono, altrimenti nome e cognome del cliente che si è avvicinato di più a tale soglia
-- 5. sedi
-- Codice, indirizzo e bilancio complessivo annuale delle 5 sedi che hanno effettuato il maggior numero di incassi, delle 5 sedi che hanno incassato di meno, delle 5 sedi che hanno speso di più e delle 5 sedi che hanno speso di meno

-- qualcosa tipo che calcoli sulle sedi tranne quelle negli usa
-- Codice, indirizzo e bilancio
-- 6. fornitori - dipendenti
-- Nomi dei fornitori per i quali l’intervallo di tempo da quando hanno effettuato il carico a quando è stato emesso un esborso a loro favore è superiore ai 90 giorni

anno - sede - netto - lordo
select year(t.ts) as anno, 
        s.indirizzo, 
        sum(saldo) as netto, 
        sum(saldo + (
            case  
            when saldo < 0 then -1 * contributi
            else contributi
            end
        )) as lordo
from transazioni t join sedi s on t.codiceSede=s.codice
group by year(t.ts), t.codiceSede order by year(t.ts) desc;

select year(ts) as anno, 
        s.indirizzo, 
        sum(saldo) as netto, 
        sum(saldo + (
            case  
            when saldo < 0 then -1 * contributi
            else contributi
            end
        )) as lordo
from transazioni t join sedi s on t.codiceSede=s.codice, (
    -- select c.ts, -1 * c.saldo from carico c where not exists (
    --     select * from pagamento p where p.tsCarico=c.ts and p.magazzino=c.magazzino
    -- )
    select c.ts, -1 * c.saldo as saldo from carico c where saldato=0
) esborsi_non_pagati
group by year(t.ts), t.codiceSede order by year(t.ts) desc;
-- //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// -- 
drop view if exists transazioni_esborsi_mancanti;
create view transazioni_esborsi_mancanti as
    select year(t.ts) as anno, s.indirizzo, t.saldo, t.contributi
        from transazioni t join sedi s on t.codiceSede=s.codice
    union all
    select year(c.ts) as anno, s.indirizzo, -1 * c.saldo as saldo, 0 as contributi 
        from ((carico c join magazzini m on c.magazzino=m.id) join sedi s on m.sedeAppartenenza=s.codice) where saldato=0;

select anno, 
        indirizzo, 
        sum(saldo) as netto, 
        sum(saldo + (
            case  
            when saldo < 0 then -1 * contributi
            else contributi
            end
        )) as lordo
from transazioni_esborsi_mancanti
group by anno, indirizzo order by anno desc;
-- select c.ts, -1 * c.saldo from carico c where not exists (
    --     select * from pagamento p where p.tsCarico=c.ts and p.magazzino=c.magazzino
    -- )

-- ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// -- 


-- Nome e tipologia delle merci per le quali sono stati emessi più esborsi o per le quali il numero di carichi supera del 30% (oppure è il doppio) quello degli scarichi, e sedi che si sono macchiate di tale vergogna.

-- create view operazioni_su_magazzino as
--     select ts, magazzino, merce, sum(quantita) as quantita, 'c' from carico
--     union
--     select ts, magazzino, merce, sum(quantita) as quantita, 's'

select codice, nome, tipo from merci m where exists (
    select 1
    from carico c where c.merce=m.codice
    group by c.merce having sum(c.quantita) > ((
        select sum(s.quantita) from scarico s where s.merce=m.codice GROUP by s.merce
    ) * 2)
)

select m.nome as nomeMerce, m.tipo as tipoMerce
    from merci m join carico c on c.merce=m.codice, magazzino
    where magazzino.id=c.magazzino
    group by c.merce having sum(c.quantita) > ((
        select sum(s.quantita) from scarico s where s.merce=m.codice GROUP by s.merce
    ) * 2)


select me.nome as nomeMerce, me.tipo as tipoMerce
    from ((merci me join contenimento on me.codice = contenimento.merce) join magazzini ma on contenimento.magazzino=ma.id)
    where not exists(
        select 1
        from carico c
        where ma.id=c.magazzino and c.merce=me.codice 
        group by c.merce having sum(c.quantita) > ((
            select sum(s.quantita) from scarico s where s.magazzino=ma.id and s.merce=me.codice GROUP by s.merce
        ) * 2)
    )


select sedi.indirizzo as `Indirizzo Sede`, d.nome as Direttore, me.nome as `Nome Merce`, me.tipo as `Tipo Merce`
    from ((((merci me join contenimento on me.codice = contenimento.merce) join magazzini ma on contenimento.magazzino=ma.id) join sedi on ma.sedeAppartenenza=sedi.codice) join dipendenti d on sedi.codice=d.sedeLavorativa and d.ruolo='direttore')
    where exists(
        select 1
        from carico c
        where ma.id=c.magazzino and c.merce=me.codice 
        group by c.merce having sum(c.quantita) > ((
            select sum(s.quantita) from scarico s where s.magazzino=ma.id and s.merce=me.codice GROUP by s.merce
        ) * 2)
    );




















select codiceSede, sum(saldo), sum(contributi), sum(saldo) + sum(contributi) from transazioni group by codiceSede;




-- Nomi dei fornitori per i quali l’intervallo di tempo da quando hanno effettuato il carico a quando è stato emesso un esborso a loro favore è superiore ai 90 giorni
-- select nome, saldo from fornitori 
--     join carico on fornitore=piva 
--     where saldato=0 and timestampdiff(day, ts, now()) >90
-- intersect
-- select * from carico

-- select s.indirizzo, d.nome, d.cognome, d.telefono, d.mail, /* f.nome, f.piva, */ timestampdiff(day, tsCarico, tsTransazione) as giorni 
--     from dipendenti d join sedi on sedeLavorativa=codice, pagamento where codiceSede=codice and timestampdiff(day, tsCarico, tsTransazione)>90 and ruolo='direttore';



(select d.nome as `nome direttore/fornitore`, d.cognome as `cognome direttore/P.IVA fornitore`, d.telefono, d.mail,  sum(timestampdiff(day, tsCarico, tsTransazione)) as `giorni sforo`      
    from dipendenti d join sedi s on sedeLavorativa=codice, pagamento 
    where codiceSede=codice 
    and timestampdiff(day, tsCarico, tsTransazione)<90 
    and ruolo='direttore' 
    and s.codice not in (
        select codice from sedi where indirizzo like '%italy%'
    ) group by d.cf limit 10)
union
(select f.nome, f.piva, f.telefono, f.mail, sum(timestampdiff(day, c.ts, now())) 
    from fornitori f join carico c on f.piva=c.fornitore 
    where saldato=0 
    and timestampdiff(month, ts, now())>4 group by f.piva limit 10);


-- avg salary ruoli
select ruolo, avg(stipendio) from dipendenti order by avg(stipendio) group by ruolo;
--
select ruolo, avg(stipendio) as `Stipendio medio per Ruolo`, -1*avg(t.saldo+-1*t.contributi) as `Spesa media della sedi per ruolo in Stipendi` 
    from (dipendenti d join retribuzioni r on cf=dipendente) 
    join transazioni t on (r.ts=t.ts and r.codiceSede=t.codiceSede) group by ruolo;


-- Le fatture emesse  all’agenzia che ha effettuato nell’arco dell’ultimo anno in media più prenotazioni

-- Per ogni mese, nome del mese, due colonne, numero massimo di clienti raggiunto, e minimo, ed indirizzo della sede dove sono stati





-- Nomi delle agenzie, codice ed indirizzo delle sedi relative, per le quali la somma degli importi delle fatture relative è superiore a quella di tutte le altre agenzie, per quella sede.
drop view if exists sedi_transazioni_fatture;
create view sedi_transazioni_fatture as
    select s.indirizzo, f.agenzia, t.saldo 
    from ((sedi s join transazioni t on s.codice=t.codiceSede) join fatture f on t.ts=f.ts and t.codiceSede=f.codiceSede);

select stf.indirizzo as `Indirizzo sede`, a.nome as `Nome Agenzia`, sum(stf.saldo) as `Importo Totale`
from sedi_transazioni_fatture stf join clienti_agenzie a on stf.agenzia=a.codiceUnivocoFatturazione
group by a.codiceUnivocoFatturazione having sum(stf.saldo) >= all (
    select sum(sedi_transazioni_fatture.saldo) from sedi_transazioni_fatture group by sedi_transazioni_fatture.agenzia
);


drop view if exists sedi_transazioni_fatture;
create view sedi_transazioni_fatture as
    select s.codice, s.indirizzo, f.agenzia, t.saldo 
    from ((sedi s join transazioni t on s.codice=t.codiceSede) join fatture f on t.ts=f.ts and t.codiceSede=f.codiceSede);

drop view if exists query6;
create view query6 as
    select stf.indirizzo as `Indirizzo sede`, a.nome as `Nome Agenzia`, sum(stf.saldo) as `Importo Totale`
    from sedi_transazioni_fatture stf join clienti_agenzie a on stf.agenzia=a.codiceUnivocoFatturazione
    group by stf.codice having sum(stf.saldo) >= all (
        select sum(sedi_transazioni_fatture.saldo) from sedi_transazioni_fatture where sedi_transazioni_fatture.codice=stf.codice and sedi_transazioni_fatture.agenzia=stf.agenzia group by sedi_transazioni_fatture.agenzia
    );

drop view if exists sedi_transazioni_fatture;
create view sedi_transazioni_fatture as
    select s.codice, s.indirizzo, f.agenzia, t.saldo 
    from ((sedi s join transazioni t on s.codice=t.codiceSede) join fatture f on t.ts=f.ts and t.codiceSede=f.codiceSede);

drop view if exists query6;
create view query6 as
    select stf.indirizzo as `Indirizzo sede`, stf.agenzia as `Codice univoco fatturazione Agenzia`, a.nome as `Nome Agenzia`, sum(stf.saldo) as `Importo Totale`
    from sedi_transazioni_fatture stf join clienti_agenzie a on stf.agenzia=a.codiceUnivocoFatturazione
    group by stf.codice having sum(stf.saldo) >= all (
        select sum(sedi_transazioni_fatture.saldo) from sedi_transazioni_fatture where sedi_transazioni_fatture.agenzia=stf.agenzia and sedi_transazioni_fatture.codice=stf.codice and sedi_transazioni_fatture.agenzia=stf.agenzia group by sedi_transazioni_fatture.agenzia
    );

select * from query6;

-- ora
select stf.indirizzo as `Indirizzo sede`, a.nome as `Nome Agenzia`, sum(stf.saldo) as `Importo Totale`
from sedi_transazioni_fatture stf join clienti_agenzie a on stf.agenzia=a.codiceUnivocoFatturazione
group by stf.codice, stf.agenzia having sum(stf.saldo) >= all (
    select sum(sedi_transazioni_fatture.saldo) from sedi_transazioni_fatture where sedi_transazioni_fatture.codice=stf.codice group by sedi_transazioni_fatture.agenzia
);
