function [int, h] = trapezi_composta (f,a,b,m)
%TRAPEZI Formula dei trapezi composta
%
% [int,h] = trapezi_composta (f,a,b,m);
%
% Dati di ingresso:
% f: funzione integranda
% a: estremo sinistro dell’intervallo di integrazione
% b: estremo destro dell’intervallo di integrazione
% m: numero di sottointervalli
% Dati di uscita:
% int: approssimazione dell’integrale definito
% h: passo di integrazione

h = (b-a)/m;

x = a:h:b;

int = (h/2)*(f(x(1))+f(x(end)));

for i = 2:m
    int = int + h*f(x(i));
end

end
