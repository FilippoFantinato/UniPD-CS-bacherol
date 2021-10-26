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

% Definizione del grado m del polinomio ai minimi quadrati
m = input('Grado m del polinomio che si vuole ottenere: ');

% Controllare che il numero di dati sia > del grado del polinomio e in caso
% contrario, dare un errore
if(n <= m)
    disp('ERROR: Il grado del polinomio è maggiore del numero dei dati inseriti.');
else
    % Chiamata della funzione least_squares
    P = least_squares(xdata, ydata, m);
    
    % Definizione del vettore xls tra [-4, 4] su cui calcolare il polinomio
    % ottenuto
    xls = linspace(a, b, NUMBER_OF_COMPONENTS);

    % Calcolo del polinomio su xls usando polyval
    yfit = polyval(P, xls);

    % Plot del grafico dei risultati ottenuti (dati e polinomio approssimante)
    hold on;
    
    title(strcat('Polinomio approssimante di grado: ', num2str(m)));
    plot(xls, yfit, 'r--', 'LineWidth', 2);
    scatter(xdata, ydata, 'MarkerFaceColor', 'b', 'MarkerEdgeColor', 'b');
    legend('Polinomio approssimante', 'Dati');
    xlabel('x');
    ylabel('y');
    
    hold off;   
end
