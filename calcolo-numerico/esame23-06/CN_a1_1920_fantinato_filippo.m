clear all;
clc;

% Costanti
NUMBER_OF_COMPONENTS = 200;

% Dati in input
frunge = @(x) 1./(1+x.^2);
a = -5;
b = 5;
n = 10;

% Print dei dati inseriti
disp("----------DATI----------");
disp("Funzione di Runge");
disp(frunge);
fprintf("Intervallo inserito: [%d, %d]\n", a, b);
fprintf("Grado del polinomio interpolante: %d\n", n);

% Genero NUMBER_OF_COMPONENTS punti equispaziati nell'intervallo [a, b]
x = linspace(a, b, NUMBER_OF_COMPONENTS);
% Calcolo la funzione di runge esatta
yrunge = frunge(x);

% Genero n+1 nodi di chebishev e ne calcolo il loro valore sulla funzione
% di Runge
xdata = (a+b)/2 + ((b-a)/2)*(-cos((0:n)*pi/n));
ydata = frunge(xdata);

% Genero il polinomio interpolante
P = polyfit(xdata, ydata, n);
% Valuto il polinomio interpolante su x
yfit = polyval(P, x);

% Plot:
% disegno i nodi di chebishev da interpolare
scatter(xdata, ydata, "MarkerFaceColor", "c", "MarkerEdgeColor", "c");

hold on;

% disegno la funzione esatta e il polinomio interpolatore
plot(x, yrunge, "r-", "LineWidth", 2);
plot(x, yfit, "b-", "LineWidth", 2);

title("Funzione di Runge | Punti di Chebishev");
xlabel("x");
ylabel("y");

legend("Punti di Chebishev", "Funzione esatta", "Polinomio interpolante");

hold off;
