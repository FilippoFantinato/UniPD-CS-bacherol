clc;
clear all;

a = input("Inserisci il valore di a: ");

ad = double(a);
as = single(a);
epsa = abs(ad-as);
epsr = abs(ad-as)/abs(ad);

fprintf("Valore di a in doppia precisione: %f\n", ad);
fprintf("Valore di a in singola precisione: %f\n", as);
fprintf("Errore assoluto: %e\n", epsa);
fprintf("Errore relativo: %e\n", epsr);
