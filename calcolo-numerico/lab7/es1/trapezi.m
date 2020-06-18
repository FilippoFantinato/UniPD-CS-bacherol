function [int, H, x] = trapezi(f, a, b, m)
%TRAPEZI Metodo dei Trapezi composto
%
% [int, H, x] = trapezi(f, a, b, m);
%
% Dati di ingresso:
% f: funzione integranda
% a: etsremo sinistro dell’ intervallo di integrazione
% b: etsremo destro dell’ intervallo di integrazione
% m: numero di sottointervalli
%
% Dati di uscita:
% int: approssimazione dell’ integrale definito
% H: passo di integrazione
% x: punti di integrazione usati per la quadratura

H = (b-a)/m;
x = a:H:b;
int = (H/2)*(f(x(1)) + f(x(end)));

for i = 2:m
    int = int + (H*f(x(i)));  
end

end
