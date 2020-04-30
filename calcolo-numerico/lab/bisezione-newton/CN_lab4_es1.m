clear all
clc
disp('METODO DI NEWTON E METODO DI BISEZIONE CONFRONTO')

% Ingresso dati
% Funzione e una derivata
f = @(x) exp(x) - 5 + x^2;
f1 = @(x) 2*x + exp(x);

% Estremi dell'intervallo
a = input("Estremo a per il metodo di Bisezione: ");
b = input("Estremo b per il metodo di Bisezione: ");

% Punto iniziale x0
x0 = input("Punto x0 iniziale per il metodo di Newton: ");

%========================================
% Tolleranza
toll = 1e-8;

% Numero massimo di iterazioni
nmax = 100;

if a > b || f(a)*f(b) > 0
	fprintf("Gli estremi dell' intervallo non rispettano le condizioni del teorema per cui a <= b e f(a)*f(b) < 0\n");
else
	% Visualizzazione di controllo dati inseriti metodo di bisezione
	fprintf('-------DATI BISEZIONE-------\n') ;
	disp('f = ') ;
	disp(f);
	fprintf("a = %f\n", a);
	fprintf("b = %f\n", b);
	fprintf ('toll = %e \n ', toll);
	fprintf ('n. max iterazioni = %d \n', nmax);

	[xvB, fxvB, nB] = bisezione(f, a, b, toll, nmax);

	% Risultati BISEZIONE
	fprintf('-------RISULTATI BISEZIONE-------\n') ;

	if nB == nmax
		disp('WARNING: Numero massimo di iterazioni raggiunto');
	else
		disp('La convergenza è stata raggiunta');
	end

	fprintf("Valore finale ascissa: %e\n", xvB(end));
	fprintf("Valore finale ordinata: %e\n", fxvB(end));
	fprintf("Numero di iterazioni: %d\n", nB);

	iterationsBisection = 1:nB;

	semilogy(iterationsBisection, abs(fxvB), 'ro-');

	hold on;

	valuesMatrixBisection = [iterationsBisection; xvB; fxvB];

	fprintf('\txn\t\tfxn\n');
	fprintf('%d\t%e, \t%e\n', valuesMatrixBisection);
end

% Visualizzazione di controllo dati inseriti metodo di newton
fprintf('-------DATI NEWTON-------\n') ;
disp('f = ') ;
disp(f);
disp('derivata di f = ');
disp(f1);
fprintf ('x0 = %f \n', x0);
fprintf ('toll = %e\n', toll);
fprintf ('n. max iterazioni = %d \n', nmax);

% Parte esecutiva
% Chiamata funzione newton
[xvN, fxvN, nN] = newton(f, f1, x0, toll, nmax);

% Risultati NEWTON
fprintf('-------RISULTATI NEWTON-------\n');

if nN == nmax
	disp('WARNING: Numero massimo di iterazioni raggiunto');
else
	disp('La convergenza è stata raggiunta');
end

fprintf('Valore ultima ascissa iterata: %e\n', xvN(end));
fprintf('Valore ultima ordinata iterata: %e\n', fxvN(end));
fprintf('Numero di iterazioni: %d\n', nN);

iterationsNewton = 1:nN;

semilogy(iterationsNewton, abs(fxvN), 'bo-');

title('Filippo Fantinato | f(x) = e^x - 5 + x^2');
xlabel('Iterazioni');
ylabel('f(x)');

valuesMatrixNewton = [iterationsNewton; xvN; fxvN];

fprintf('\txn\t\tfxn\n');
fprintf('%d\t%e, \t%e\n', valuesMatrixNewton);

hold off;
