function [x,k,steps,flag] = jacobi (A,b,x0,toll,kmax)
% JACOBI Metodo di Jacobi per la risoluzione di un sistema lineare
% con test di arresto sulla norma della differenza di due
% iterate successive
% Uso:
% [x,k,flag] = jacobi (A,b,x0,toll,kmax)
% Dati di ingresso:
% A matrice dei coefficienti
% b vettore colonna dei termini noti
% x0 vettore colonna iniziale
% toll tolleranza per il test di arresto
% kmax numero massimo di iterazioni
% Dati di uscita:
% x array che contiene per colonne le iterate (vettori) del metodo
% k numero delle iterazioni effettuate
% steps vettore di lunghezza k avente quale j-sima componente \|x(:,j+1) - x(:,j)\|_2,j=1,\ldots,k.
% flag vale 1 se per qualche indice "i" si abbia a(i,i)=0 ed in tal caso si ponga k=0,
%. x=[], steps=[],
% vale 2 se il numero di iterazioni \’e strettamente maggiore di kmax.
% vale 0 altrimenti.



end
