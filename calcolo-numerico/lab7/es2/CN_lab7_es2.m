clear all;
clc;

% Script per il calcolo di integrali usando le regole di quadratura
% composte (Trapezi e Simpson)
% necessita delle funzioni trapezi.m e simpson.m

% Costanti
ERR_FILENAME = 'tab_err.txt';

% Dati in ingresso
% Definizione della funzione integranda (handle function)
f = @(x) sin(x) + 1;
% f = @(x) 5*x.^4 - 6*x.^2 + 1;

% definisco la primitiva di g = int(f)
g = @(x) -cos(x) + x;
% g = @(x) x.^5 - 2*x.^3 + x;

% e gli estremi di integrazione;
a = 0;
b = 12;

% a = -1;
% b = 1;

% num di raddoppi
m = [ ];
nm = input('Inserire il numero di volte in cui verrà raddoppiata m: ');

% Ricapitolo dati inseriti
disp('----------DATI INSERITI----------')
disp('Funzione integranda: ');
disp(f);
disp('Funzione primitiva: ');
disp(g);
fprintf('Intervallo di integrazione: [%d, %d]\n', a, b);
fprintf('Numero di volte in cui verrà raddoppiato m: %d\n\n', nm);

% Inizializzazione degli array che conterranno gli errori relativi ad ogni
% metodo
err_trap = [];
err_sim = [];

% calcolo dell'integrale esatto
int_exact = g(b) - g(a);

actual_m = 1;

% Apertura del file
fileId = fopen(ERR_FILENAME, 'w');

for i = 1:nm
    % Raddoppio m
	m(i) = 2*actual_m;
    actual_m = m(i);
    
	% Calcolo dell'integrale utilizzando le formule di quadratura numerica
	% Trapezi composta
	[int_t, H_t, xint_t] = trapezi(f, a, b, actual_m);

	% Simpson composta
	[int_s, h_s, xint_s] = simpson(f, a, b, actual_m);

	% Calcolo dell'errore commesso

	% errore trapezi
	err_trap(i) = abs(int_exact - int_t);

	% errore simpson
	err_sim(i) = abs(int_exact - int_s);
    
    % Scrivo i dati appena calcolati sul file
    fprintf(fileId, '%e\t%e\t%e\n', actual_m, err_trap(i), err_sim(i));
end

figure('Name', 'Grafico degli Errori');

% Grafico dell'errore del metodo dei trapezi
loglog(m, err_trap, '-bv', 'LineWidth', 2);

hold on;
title(strcat('f(x)=', func2str(f), ' | Raddoppi: ', int2str(nm)));

% Grafico dell'errore del metodo di Simpson
loglog(m, err_sim, '-ro', 'LineWidth', 2);

legend('Errore trapezi', 'Errore Simpson');
xlabel('m');
ylabel('errore');

hold off;

% Visualizzo la tabella degli errori per iterazione
mErrsMatrix = [m; err_trap; err_sim]; 
fprintf('Tabella errori per iterazione: \n');
fprintf('M\tErrore Trapezi\tErrore Simpson\n');
fprintf('%d\t%e\t%e\n', mErrsMatrix);

% Chiudo il file
fclose(fileId);
