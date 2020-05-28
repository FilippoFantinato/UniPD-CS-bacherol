function[int, h, x] = simpson(f, a, b, m)
% SIMPSON: Metodo di Simpson composto
%
% [int, h, x] = simpson(f, a, b, m);
%
% Dati di ingresso:
% f: funzione integranda
% a: estremo sinistro dell’ intervallo di integrazione
% b: estremo destro dell’ intervallo di integrazione
% m: numero di sottointervalli
%
% Dati di uscita:
% int: approssimazione dell’ integrale definito
% h: passo di integrazione
% x: ascisse dei punti di integrazione
H = (b-a) /m ; % AMPIEZZA INTERVALLO .
h = H / 2; % passo di integrazione, visto come distanza tra nodi successivi,
            % che corrisponde all’ ampiezza del semiintervallo

x = a:h:b;

int = 0;

for i = 1:2:2*m-1
    int = int + (f(x(i))+4*f(x(i+1))+f(x(i+2)));
end

int = h/3 * int;

end
