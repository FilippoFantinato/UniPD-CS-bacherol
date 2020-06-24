function [xv, fxv, n, flag] = secante(f, x0, x1, toll, nmax)

% Dati di ingresso:
% f: funzione (inline function)
% x0: primo valore iniziale
% x1: secondo valore iniziale
% toll: tolleranza richiesta per il valore assoluto della differenza di due iterate
% successive
% nmax: massimo numero di iterazioni permesse
%
% Dati di uscita:
% xv: vettore colonna contenente le iterate
% fxv: vettore colonna contenente i corrispondenti residui
% n: numero di iterazioni effettuate
% flag: se flag = 1 si e’ verificata una divisione per zero o
% si sono raggiunte le nmax iterazioni.

f1 = @(xn, xn1) (f(xn) - f(xn1))/(xn - xn1);

xv = [x0, x1];

fxv = [f(x0), f(x1)];
n = 2;
flag = 0;

diff = toll + 1;

while n < nmax && abs(diff) >= toll
    
    den = xv(n) - xv(n-1);
    
    if den == 0
        flag = 1;
    else
        diff = -(f(xv(n))/((f(xv(n))-f(xv(n-1)))/den));
        
        xv(n+1)=xv(n) + diff;
        fxv(n+1)=f(xv(n+1));
        
        n = n+1;
    end
    
end

if n >= nmax
    flag = 1;
end

end
