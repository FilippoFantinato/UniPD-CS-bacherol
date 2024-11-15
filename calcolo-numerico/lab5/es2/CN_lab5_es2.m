clear all;
clc;

frunge = @(x) 1./(1 + x.^2);

% Dati:
a = -5;
b = 5;
n = 10;
numberOfComponents = 200;

% Ricapitolo dei dati:
fprintf('Dati inseriti: \n');
fprintf('Intervallo: [%d, %d]\n', a, b);
fprintf('Grado polinomio: %d\n', n);
fprintf('Numero componenti del vettore equispaziato x: %d\n', numberOfComponents);

% Calcolo della funzione di runge (esatta) su un vettore equispaziato di
% n+1 entrate tra [a, b]
xdata = linspace(a, b, n+1);
ydata = frunge(xdata);

% Calcolo vettore equispaziato di @numberOfComponents componenti
x = linspace(a, b, numberOfComponents);

% Caso 1: Interpolazione dei dati con un polinomio di grado n e calcolo dei
% valori su x
P = polyfit(xdata, ydata, n);
yfit = polyval(P, x);

% Caso 2: Interpolazione dei dati con n splines e calcolo dei valori su x
yspline = spline(xdata, ydata, x);

% Caso 3: Interpolazione dei dati con n funzioni lineari a tratti e
% calcolo dei valori su x
ypl = interp1(xdata, ydata, x);

% Calcolo Errori

y = frunge(x);

% 1. Interpolante con un polinomio di grado n e funzione esatta
errP = yfit - y;

% 2. Interpolante con n splines e funzione esatta
errSplines = yspline - y;

% 3. Interpolante con n funzioni lineari a tratti e funzione esatta
errPl = ypl - y;


% Plot del primo grafico: Funzione esatta, dati e polinomio interpolante
figure('Name', 'Grafico 1');

hold on;

% Funzione esatta
plot(x, y, '--k', 'LineWidth', 2);
% Dati
scatter(xdata, ydata, 'MarkerFaceColor', 'r', 'MarkerEdgeColor', 'r');
% Polinomio interpolante
plot(x, yfit, '--b', 'LineWidth', 2);
legend('Funzione', 'Dati', 'Polinomio Interpolante', 'location', 'south');
xlabel('x');
ylabel('y');

hold off;

% Plot del secondo grafico: Funzione esatta, dati, splines e funzioni lineari a tratti
figure('Name', 'Grafico 2');

hold on;

% Funzione esatta
plot(x, y, '--k', 'LineWidth', 2);
% Dati
scatter(xdata, ydata, 'MarkerFaceColor', 'r', 'MarkerEdgeColor', 'r');
% Splines
plot(x, yspline, '-m');
% Funzioni lineari a tratti
plot(x, ypl, 'c');
legend('Funzione', 'Dati', 'Spline int. a tratti', 'Lineare a tratti');
xlabel('x');
ylabel('y');

hold off;

% Plot del terzo grafico: Errore delle tre interpolazioni calcolato su x
figure('Name', 'Grafico 3');

hold on;

% Errore polinomio interpolante
plot(x, errP, '-b', 'LineWidth', 2);
% Errore splines
plot(x, errSplines, '-r', 'LineWidth', 2);
% Errore funzioni lineri a tratti
plot(x, errPl, '-y', 'LineWidth', 2);
legend('Err int polinomio grado n', 'Err spline (a tratti)', 'Err lin a tratti', 'location', 'north');
xlabel('x');
ylabel('y');

hold off;

