clear all
clc
disp('METODO DI NEWTON E METODO DELLA BISEZIONE CONFRONTO')

% Ingresso dati
% Funzione e una derivata

%-----------Prima funzione-----------
f = @(x) sqrt(x + 1) - exp(-x);
f1 = @(x) exp(-x) + 1/(2*sqrt(x + 1));

%-----------Seconda funzione-----------
% f = @(x) exp(x) - 5 + x^2;
% f1 = @(x) 2*x + exp(x);

%-----------Terza funzione-----------
% f = @(x) 3*x - cos(x);
% f1 = @(x) sin(x) + 3;

%-----------Quarta funzione-----------
% f = @(x) x + log(x);
% f1 = @(x) 1/x + 1;

%-----------Quinta funzione-----------
% f = @(x) sin(x) - (x^2)/2;
% f1 = @(x) cos(x) - x;

% Estremi dell'intervallo
a = input("Estremo a per il metodo della Bisezione: ");
b = input("Estremo b per il metodo della Bisezione: ");

% Punto iniziale x0
x0 = input("Punto x0 iniziale per il metodo di Newton: ");

%========================================
% Tolleranza
toll = 1e-8;

% Numero massimo di iterazioni
nmax = 100;

% Print della funzione da analizzare
disp('Funzione = ') ;
disp(f);

% Controllo della validità degli estremi inseriti per l'esecuzione del
% metodo di bisezione
if a > b || f(a)*f(b) > 0
	fprintf("Gli estremi dell'intervallo non rispettano le condizioni del teorema per cui a <= b e f(a)*f(b) < 0\n");
else
	% Visualizzazione di controllo dati inseriti metodo di bisezione
	fprintf('-------DATI BISEZIONE-------\n') ;
	fprintf("a = %f\n", a);
	fprintf("b = %f\n", b);
	fprintf('Tolleranza = %e \n ', toll);
	fprintf('Numero massimo iterazioni = %d \n', nmax);
   
    % Parte esecutiva
    % Chiamata funzione bisezione
	[xvB, fxvB, nB] = bisezione(f, a, b, toll, nmax);

	% Risultati bisezione
	fprintf('-------RISULTATI BISEZIONE-------\n') ;

    % Controllo se le iterazioni hanno raggiunto il numero massimo
	if nB == nmax
		disp('WARNING: Numero massimo di iterazioni raggiunto');
	else
		disp('La convergenza è stata raggiunta');
	end

	fprintf("Valore finale ascissa: %e\n", xvB(end));
	fprintf("Valore finale ordinata: %e\n", fxvB(end));
	fprintf("Numero di iterazioni: %d\n", nB);

	iterationsBisection = 1:nB;

    semilogy(iterationsBisection, abs(fxvB), 'ro-', 'LineWidth', 2, 'MarkerFaceColor', 'green', 'MarkerEdgeColor','green');

 	hold on;

    % Print della tabella contenente i valori presenti nei vettori xvB e
    % fxvB ottenuti dall'esecuzione della funzione "bisezione" per ogni
    % iterazione
	valuesMatrixBisection = [iterationsBisection; xvB; fxvB];

	fprintf('\txb\t\tfxb\n');
	fprintf('%d\t%e, \t%e\n', valuesMatrixBisection);
end

% Visualizzazione di controllo dati inseriti metodo di newton
fprintf('-------DATI NEWTON-------\n') ;
disp('Derivata di f = ');
disp(f1);
fprintf('x0 = %f \n', x0);
fprintf('Tolleranza = %e\n', toll);
fprintf('Numero massimo iterazioni = %d \n', nmax);

% Parte esecutiva
% Chiamata funzione newton
[xvN, fxvN, nN] = newton(f, f1, x0, toll, nmax);

% Risultati newton
fprintf('-------RISULTATI NEWTON-------\n');

% Controllo se le iterazioni hanno raggiunto il numero massimo
if nN == nmax
	disp('WARNING: Numero massimo di iterazioni raggiunto');
else
	disp('La convergenza è stata raggiunta');
end

fprintf('Valore finale ascissa: %e\n', xvN(end));
fprintf('Valore finale ordinata: %e\n', fxvN(end));
fprintf('Numero di iterazioni: %d\n', nN);

iterationsNewton = 1:nN;

semilogy(iterationsNewton, abs(fxvN), 'bo-', 'LineWidth', 2, 'MarkerFaceColor', 'red', 'MarkerEdgeColor','red');

% Aggiunta del titolo, della label sull'asse delle ascisse e delle ordinate e
% della legenda
title('Filippo Fantinato | f(x) = sqrt(x + 1) - exp(-x)');
xlabel('Iterazioni');
ylabel('Residui');
legend('Metodo della Bisezione', 'Metodo di Newton');

% Print della tabella contenente i valori presenti nei vettori xvN e fxvN
% ottenuti dall'esecuzione della funzione "newton" per ogni iterazione
valuesMatrixNewton = [iterationsNewton; xvN; fxvN];

fprintf('\txn\t\tfxn\n');
fprintf('%d\t%e, \t%e\n', valuesMatrixNewton);

hold off;
