clear all;
clc;

% Script per il calcolo di integrali usando le regole di quadratura
% composte (Trapezi e Simpson)
% necessita delle funzioni trapezi.m e simpson.m

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

% num di intervalli di ampiezza H = 2*h
m = 3;

% Ricapitolo dati inseriti
disp('----------DATI INSERITI----------')
disp('Funzione integranda: ');
disp(f);
disp('Funzione primitiva: ');
disp(g);
fprintf('Intervallo di integrazione: [%d, %d]\n', a, b);
fprintf('Numero di intervalli di ampiezza H: %d\n\n', m);

% Calcolo dell'integrale utilizzando le formule di quadratura numerica
% Trapezi composta
[int_t, H_t, xint_t] = trapezi(f, a, b, m);

% Valuto f nei punti di integrazione xint_t
yint_t = f(xint_t);

% Simpson composta
[int_s, h_s, xint_s] = simpson(f, a, b, m);

% Valuto f nei punti di integrazione xint_s
yint_s = f(xint_s);

% Disegno la funzione f nell'intervallo a b (su almeno 100 punti)
x = linspace(a, b, 100);
y = f(x);

hold on;
title(strcat('f(x)=', func2str(f), ' | m=', num2str(m)));

plot(x, y, '-b', 'LineWidth', 2);

% aggiungo al grafico i punti usati per L'integrazione usando la 
% formula dei trapezi composta e i polinomi usati nell'integrazione (lineari a tratti su ogni intervallo)

plot(xint_t, yint_t, '-gv', 'LineWidth', 2, 'MarkerEdgeColor', 'g', 'MarkerFaceColor', 'g', 'MarkerSize', 7);

% aggiungere al grafico i punti usati per l'integrazione usando la formula di simpson composta
scatter(xint_s, yint_s, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');

% (m intervalli e 2m+1 nodi da x_ 1 a x_(2m+1)) per ognuno degli intervalli calcolo e disegno il polinomio di grado 2 interpolante i tre nodi dell'intervallo
% intervallo iniziale nodi x_1 x_2 x_3
% intervallo i-esimo, nodi x_i x_i+1 x_1+2
% intervallo finale, nodi x_2m-1 x_2m x_2m+1
for i = 1:2:length(xint_s)-2
    P = polyfit(xint_s(i:i+2), yint_s(i:i+2), 2);
    xfit = linspace(xint_s(i), xint_s(i+2), 100);
    yfit = polyval(P, xfit);
    plot(xfit, yfit, '-r', 'LineWidth', 2);
end

legend('Funzione', 'Trapezi', 'Punti di int.', 'Simpson');

xlabel('x');
ylabel('y');

hold off;

% Calcolo dell'errore commesso
% calcolo l'integrale esatto
int_exact = g(b) - g(a);

% errore trapezi
err_trap = abs(int_exact - int_t);

% errore simpson
err_sim = abs(int_exact - int_s);

% Visualizzo gli errori
disp('----------ERRORE----------')
fprintf('Valore esatto: %e\n', int_exact);
fprintf('Trapezi errore: %e\n', err_trap);
fprintf('Simpson errore: %e\n', err_sim);
