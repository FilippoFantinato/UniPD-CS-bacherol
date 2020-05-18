clear all;
clc;

% Costanti
DATI_FILENAME = 'dati.txt';
ERR_FILENAME = 'err.txt';
NUMBER_OF_COMPONENTS = 200;

% Lettura degli N dati di ingresso dal file dati.txt
load(DATI_FILENAME);

xdata = dati(:, 1);
ydata = dati(:, 2);

n = length(xdata);
a = -4;
b = 4;

errors = [ ];

mVector = 1:6;

% Ciclo for da 1 a 6
for m = mVector
	% Chiamata della funzione least_squares
	P = least_squares(xdata, ydata, m);

	% Definizione del vettore xls tra [-4, 4] su cui calcolare il polinomio
	% ottenuto
	xls = linspace(a, b, NUMBER_OF_COMPONENTS);

	% Calcolo del polinomio su xls usando polyval
	yfit = polyval(P, xls);

	% Calcolo dell'errore quadratico medio
	polxdata = polyval(P, xdata);
	err = norm(ydata - polxdata);
	errors = [errors err];

	% Plot del grafico dei risultati ottenuti (dati e polinomio approssimante)
    figure('Name', num2str(m));
	hold on;

	title(strcat('Polinomio approssimante di grado: ', num2str(m)));
	plot(xls, yfit, 'r--', 'LineWidth', 2);
	scatter(xdata, ydata, 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b');
	legend('Polinomio approssimante', 'Dati');
	xlabel('x');
	ylabel('y');

	hold off;
end

mErrMatrix = [mVector; errors]; 

fprintf('Errori quadratici medi: \n');
fprintf('Grado\tErr\n');
fprintf('%d\t%e\n', mErrMatrix);

mErrMatrix = mErrMatrix';

save(ERR_FILENAME, 'mErrMatrix', '-ascii');
