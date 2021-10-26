set foreign_key_checks = 0;

drop table if exists sedi;
drop table if exists dipendenti;
drop table if exists sale;
drop table if exists tavoli;
drop table if exists clienti_singoli;
drop table if exists clienti_agenzie;
drop table if exists prenotazioni;
drop table if exists prenotazioniTavoli;
drop table if exists magazzini;
drop table if exists merci;
drop table if exists contenimento;
drop table if exists scarico;
drop table if exists fornitori;
drop table if exists carico;
drop table if exists transazioni;
drop table if exists ricevute;
drop table if exists fatture;
drop table if exists retribuzioni;
drop table if exists pagamento;
 
create table sedi(
 codice      int(10)         auto_increment  primary key,
 mail        varchar(100)    not null        unique    check (mail like '%_@__%.__%'),
 telefono    varchar(15)     not null        unique,
 indirizzo   varchar(100)    not null        unique
);

create table dipendenti (
 cf              char(16)                primary key,
 nome            varchar(30)             not null,
 cognome         varchar(30)             not null,
 stipendio       decimal(15,2) unsigned  not null    check (stipendio <> 0),
 telefono        varchar(15)             unique      not null,
 mail            varchar(100)            unique      check (mail like '%_@__%.__%'),
 ruolo           enum("cuoco", "cameriere", "cassiere", "caposala", "direttore") not null,
 sedeLavorativa  int(10)                 not null,
	foreign key (sedeLavorativa) references sedi(codice)
);

create table sale (
 codiceSede  int(10),
 numero      tinyint unsigned                check (numero <> 0),
 caposala    char(16)            unique      not null,
	primary key (codiceSede, numero),
	foreign key (codiceSede)    references sedi(codice),
	foreign key (caposala)      references dipendenti(cf)
);

create table tavoli (
 codiceSede              int(10),
 sala                  tinyint unsigned                check (sala <> 0),
 numero             smallint unsigned             check (numero <> 0),
 coperti                 tinyint  unsigned   not null    check(coperti <> 0),
 responsabileServizio    char(16) not null,
	
 primary key (codiceSede, sala, numero),
	foreign key (codiceSede, sala)   references sale(codiceSede, numero),
	foreign key (responsabileServizio)      references dipendenti(cf)
);

create table clienti_singoli(
 contatto    varchar(100)   primary key,
 nome        varchar(30),
 cognome     varchar(30)    not null,
	unique(contatto, cognome)
);

create table clienti_agenzie(
 codiceUnivocoFatturazione   varchar(100)    primary key, 
 nome                        varchar(50)     not null,
 mail                        varchar(100)    unique        not null check (mail like '%_@__%.__%'),
 telefono                    varchar(15)     unique        not null
);

create table prenotazioni(
 id              int unsigned    auto_increment      primary key,
 data            date            not null,
 oraInizio       time            not null,
 oraFine         time            not null, -- forse togliere not null, se null trigger setta a oraInizio + 1
 numeroPersone   smallint unsigned        not null            check (numeroPersone <> 0),
 cliente         varchar(100)    not null
);

create table prenotazioniTavoli(
 id_Prenotazione     int unsigned,
 codiceSede          int(10),
	numeroSala   tinyint unsigned    not null,
 numeroTavolo        smallint unsigned             not null,
	
 primary key (id_Prenotazione, codiceSede, numeroSala, numeroTavolo),
	foreign key (id_Prenotazione)      references prenotazioni(id),
	foreign key (codiceSede, numeroSala, numeroTavolo)      references tavoli(codiceSede, sala, numero)
);

create table magazzini(
 id                  int(10)         zerofill    primary key,
 sedeAppartenenza    int(10)         not null,
 indirizzo           varchar(100)    unique      not null,
	foreign key (sedeAppartenenza) references sedi(codice)
);


create table merci(
	codice  varchar(20)     primary key,
	tipo    varchar(20)     not null,
	nome    varchar(255)     not null
);

create table contenimento(
	magazzino           int(10)         zerofill,
	merce               varchar(20),
	quantitaGiacenza    mediumint       unsigned  default 0,
	primary key (magazzino, merce),
	foreign key (magazzino) references magazzini(id),
	foreign key (merce)     references merci(codice)
);

create table scarico(
	ts          timestamp   default CURRENT_TIMESTAMP,
	magazzino   int(10)     zerofill,
	merce       varchar(20) not null,
	quantita    smallint    unsigned not null check(quantita <> 0),

	primary key (ts, magazzino),
	foreign key (magazzino) references magazzini(id),
	foreign key (merce)     references merci(codice)
);

create table fornitori(
	piva        char(11)        primary key,
	nome        varchar(50)     not null,
	mail        varchar(100)    unique       not null    check (mail like '%_@__%.__%'),
 telefono    varchar(15)     unique       not null
);

create table carico(
	ts          timestamp   default CURRENT_TIMESTAMP,
	magazzino   int(10)     zerofill,
	merce       varchar(20) not null,
	quantita    smallint    unsigned check(quantita<>0),
	saldato     boolean     default 0,
	saldo       smallint    unsigned check (saldo<>0),
	fornitore   char(11) not null,
	primary key (ts, magazzino),
	foreign key (magazzino) references magazzini(id),
	foreign key (merce)     references merci(codice),
	foreign key (fornitore) references fornitori(piva)
);

create table transazioni(
	codiceSede      int(10),
	ts              timestamp           default CURRENT_TIMESTAMP,
	tipologia       enum('A', 'R', 'F', 'S', 'E') not null,
	saldo           int                 not null check(saldo<>0),
	contributi      smallint unsigned   not null,
	check (((tipologia='R' or tipologia='F') and saldo > 0) or ((tipologia='S' or tipologia='E') and saldo < 0)),
	primary key (codiceSede, ts),
	foreign key (codiceSede) references sedi(codice)
);

create table ricevute(
	progressivoRicevute     int unsigned    not null    check (progressivoRicevute <> 0),
	codiceSede              int(10),
	ts                      timestamp,
	primary key (codiceSede, ts),
	foreign key (codiceSede, ts)            references transazioni(codiceSede, ts)
);

create table fatture(
	progressivoFatture      int unsigned    not null    check (progressivoFatture <> 0),
	codiceSede              int(10),
	ts                      timestamp,
	primary key (codiceSede, ts),
	foreign key (codiceSede, ts)  references transazioni(codiceSede, ts)
);

create table retribuzioni(
	dipendente      char(16),
	codiceSede      int(10),
	ts              timestamp,
	primary key (dipendente, codiceSede, ts),
	foreign key (dipendente)        references dipendenti(cf),
	foreign key (codiceSede, ts)    references transazioni(codiceSede, ts)
);

create table pagamento(
	tsCarico        timestamp,
	magazzino       int(10)     zerofill,
	tsTransazione   timestamp,
	codiceSede      int(10),
	primary key (tsCarico, magazzino, tsTransazione, codiceSede),
	foreign key (tsCarico, magazzino)      references carico(ts, magazzino),
	foreign key (codiceSede, tsTransazione) references transazioni(codiceSede, ts)
);