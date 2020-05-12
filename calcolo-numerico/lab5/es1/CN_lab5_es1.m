% Script per la rappresentazione di un polinomio in un dato intervallo
% Calcolo del polinomio con la regola di Horner e confronto con la funzione polival.
% Richiede come input i coefficienti del polinomio e il vettore dei punti nei quali si vuole calcolare il valore del polinomio

clear all;
clc;

% Dati di input:
%   Vettore dei coefficienti del polinomio (in ordine decrescente)
P = [2, 7, 5, 4, 1, 3];
% P = [-2, 5, 4, 0, 1, 0];

%   Vettore dei punti su cui si vuole valutare il polinomio
a = input("Inserisci l'estremo sinistro dell'intervallo: ");
b = input("Inserisci l'estremo destro dell'intervallo: ");

% a = -3;
% b = 1;

% a = -1;
% b = 1;

if(a > b)
    disp("WARNING: L'intervallo sinistro è maggiore di quello destro, quindi verranno invertiti");
    c = a;
    a = b;
    b = c;
end

%   Numero di punti
xDim = input("Inserisci il numero di punti da generare tra l'intervallo specificato prima: ");

% xDim = 200;

if(xDim < 0)
    disp("WARNING: Il numero di punti inserito è negativo, quindi verrà fatto diventare positivo");
    xDim = -xDim;
end

% Ricapitolo dati inseriti:
disp('Dati inseriti: ');
fprintf('Coefficenti del polinomio: \n');
fprintf('%d ', P);
fprintf('\n');
fprintf('Intervallo: [%d, %d]\n', a, b);
fprintf('Numero di punti: %d\n', xDim);

% Generazione del vettore x
x = linspace(a, b, xDim);

% funzione Horner
yh = horner(P, x);

% forma tradizionale (funzione polinomio)
ypol = polinomio(P, x);

% polyval
yfit = polyval(P, x);

% calcolo l'errore
% pol_horner − polyval
err_horner = yh - yfit;

% pol_trad − polyval
err_pol = ypol - yfit;

% grafico del polinomio di horner e dell'errore commesso
figure('Name', 'Horner');

hold on;

plot(x, yh, 'b', 'LineWidth', 2);
plot(x, err_horner, 'r', 'LineWidth', 2);

legend('Pol. calcolato con la regola di Horner', 'Errore');
xlabel('x');
ylabel('yh');

hold off;

% grafico del polinomio "tradizionale" e dell'errore commesso
figure('Name', 'Polinomio');

hold on;

plot(x, ypol, 'g', 'LineWidth', 2);
plot(x, err_pol, 'r','LineWidth', 2);

legend('Pol. calcolato con la forma tradizionale', 'Errore');
xlabel('x');
ylabel('ypol');

hold off;
