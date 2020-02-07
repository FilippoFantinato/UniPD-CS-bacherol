drop table if EXISTS impiegato;
drop table if EXISTS lavora;
drop table if EXISTS azienda;

create table impiegato(
	cf varchar(255) not null PRIMARY KEY,
	nome varchar(255) not null,
	cognome varchar(255) not null
);

create table azienda(
	piva varchar(255) not null PRIMARY KEY,
	nazione varchar(255) not null
);

create table lavora(
	cf varchar(255),
	piva varchar(255),
	datainizio date,
	datafine date,
    PRIMARY KEY(cf, piva, datainizio),
    foreign key (cf) REFERENCES impiegato(cf),
    foreign key (piva) REFERENCES azienda(piva)
);

-- Es 1
drop view if EXISTS v;

create view v as select * from (lavora NATURAL join azienda);

select v1.cf from v v1 join v v2 on v1.cf=v2.cf where v1.nazione<>v2.nazione

-- Es 2
SELECT cf FROM lavora WHERE datafine is null group by cf HAVING count(*) = 1

-- Es 3
SELECT cognome FROM impiegato WHERE cf in(
    select cf from lavora group by cf HAVING count(DISTINCT piva) = (
        select count(*) from azienda))
