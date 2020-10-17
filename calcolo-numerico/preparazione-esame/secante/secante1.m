
function [xv,fxv,n,flag]=secante1(f,x0,x1,toll,nmax)

% SECANTE Metodo della secante
% Uso:
% [xv, fxv, n, flag] = secante (f, x0, x1, toll, nmax)
%
% Dati di ingresso:
% f: funzione
% x0: primo valore iniziale
% x1: secondo valore iniziale
% toll: tolleranza richiesta per il valore assoluto della differenza di due iterate
%       successive
% nmax: massimo numero di iterazioni permesse
%
% Dati di uscita:
% xv: vettore contenente le iterate
% fxv: vettore contenente i corrispondenti residui
% n: numero di iterazioni effettuate
% flag: se flag = 1 si e' effettuata un eventuale divisione per zero o 
%       uscita per un numero di iterazioni maggiori di nmax.

flag=0;

n=1;
xv=[x0; x1];

xold=x0;
x=x1;
xv=[x0; x1];
fold=feval(f,xold);
fnew=feval(f,x);
fxv=[fold; fnew];
absdiff=toll+1;

while absdiff >= toll & n < nmax
    
    den=fnew-fold;
    if den == 0
        flag=1;
    else
        fdiff=-(fnew*(x-xold))/den;
    end
    xold=x;
    fold=fnew;
    x=x+fdiff;
    
    fnew=feval(f,x);
    fxv=[fxv; fnew];
    
    absdiff=abs(fdiff);
    xv=[xv; x];
    n=n+1;
    
end

if n >= nmax
    flag=1;
end
