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
% a = 0;
% b = 12;

a = -1;
b = 1;

% num di intervalli di ampiezza H = 2*h
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
	err_trap(i) = int_exact - int_t;

	% errore simpson
	err_sim(i) = int_exact - int_s;
end


figure('Name', 'Errori');
% Grafico dell'errore del metodo dei trapezi
loglog(m, err_trap, '-bo', 'LineWidth', 2);

hold on;
% Grafico dell'errore del metodo di Simpson
loglog(m, err_sim, '-ro', 'LineWidth', 2);

legend('Errore trapezi', 'Errore Simpson');
xlabel('m');
ylabel('errore');

hold off
