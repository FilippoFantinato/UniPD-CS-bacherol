clear all;
clc;

% Costanti
TOLL = 10^-10;
NMAX = 100;

OUTPUT_FILE = "tabella.txt";

% Input dei dati richiesti
f =  @(x) x^2-1+exp(-x);% input("Inserisci la funzione di cui calcolare gli zeri: ");
x0 = 0.6;% input("Inserisci x0: ");
x1 = 0.8;% input("Inserisci x1: ");
% f = inline(funcS, 'x');

% Visualizzazione dei dati inseriti
disp("----------DATI INSERITI----------");
disp("Funzione: ");
disp(f);
fprintf("x0 = %f\n", x0);
fprintf("x1 = %f\n", x1);
fprintf("Tolleranza: %e\n", TOLL);
fprintf("Numero massimo di iterazioni: %d\n", NMAX);

% Eseguo la funzione secante
[xv, fxv, n, flag] = secante1(f, x0, x1, TOLL, NMAX);

% Plot del grafico
semilogy(1:length(fxv), abs(fxv), "ro--", "LineWidth", 2, "MarkerFaceColor", "b", "MarkerEdgeColor", "b");
title(strcat("Funzione: ", func2str(f)));
xlabel("Iterazioni");
ylabel("Residui");
legend("residuo secante");

% Print dei dati
disp("----------DATI OTTENUTI----------");
fprintf("Zero: %e\n", xv(end));
fprintf("Numero di iterazioni: %f\n", n);
if(flag == 1)
    disp("WARNING: o il numero di iterazioni massime è stato superato o è stata eseguita una divisione per zero");
end

% tabella(xv, OUTPUT_FILE);

