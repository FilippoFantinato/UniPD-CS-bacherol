clear all
clc
disp('METODO DI NEWTON')

% Ingresso dati
% Funzione e una derivata
f = @(x) x^2 - 2;
f1 = @(x) 2*x;

% Punto iniziale x0
x0 = 200;

%========================================
% Tolleranza
toll = 1e-8;

% Numero massimo di iterazioni
nmax = 100;


% Visualizzazione di controllo dati inseriti
fprintf('-------DATI-------\n') ;
disp('f = ') ;
disp(f);
disp('derivata di f = ');
disp(f1);
fprintf ('x0 = %f \n ', x0);
fprintf ('toll = %f \n ', toll);
fprintf ('n. max iterazioni = %f \n', nmax);

% Parte esecutiva
% Chiamata funzione newton
[xv, fxv, n] = newton(f, f1, x0, toll, nmax);

if n == nmax
	disp('WARNING: Numero massimo di iterazioni raggiunto');
else
	disp('La convergenza è stata raggiunta');
end

% Risultati
fprintf('-------RISULTATI-------\n');

fprintf('Valore ultima ascissa iterata: %e\n', xv(end));
fprintf('Valore ultima ordinata iterata: %e\n', fxv(end));
fprintf('Numero di iterazioni: %0.f\n', n);

iterationsNewton = 1:n;

semilogy(iterationsNewton, abs(fxv), 'bo-');

title('Filippo Fantinato | f(x) = x^2 - 2');
xlabel('x');
ylabel('f(x)');

valuesMatrix = [iterationsNewton; xv; fxv];

fprintf('\txn\t\tfxn\n');
fprintf('%d\t%e, \t%e\n', valuesMatrix);
