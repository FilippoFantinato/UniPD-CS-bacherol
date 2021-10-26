format long;
clc;

disp("METODO DI BISEZIONE");

f = @(x) sqrt(x + 1) - exp(-x);
a = input("Estremo a: ");
b = input("Estremo b: ");
toll = 1e-8; % input("Tolleranza: ");
nmax = 100; % input("Numero massimo di iterazioni: ");

if a > b || f(a)*f(b) > 0
	fprintf("Gli estremi dell' intervallo non rispettano le condizioni del teorema per cui a <= b e f(a)*f(b) < 0\n");
else

	disp('--------DATI--------');
	disp('Funzione: ');
	disp(f);
	fprintf("a = %f\n", a);
	fprintf("b = %f\n", b);
	fprintf("toll = %e\n", toll);
	fprintf("Numero massimo di iterazioni = %f\n", nmax);

	[xv, fxv, n] = bisezione(f, a, b, toll, nmax);

	if n == nmax
		fprintf("WARNING: E' stato riaggiunto il massimo numero di iterazioni indicato\n");
	else
		fprintf("Valore finale ascissa: %f\n", xv(end));
		fprintf("Valore finale ordinata: %f\n", fxv(end));
		fprintf("Numero di iterazioni: %0.f\n", n);

		semilogy(1:n, abs(fxv), 'Ob-', 'LineWidth', 2, 'MarkerFaceColor', 'red', 'MarkerEdgeColor','red');
        
        title('Filippo Fantinato | f(x) = sqrt(x + 1) - exp(-x)');
        xlabel('Iterazioni');
        ylabel('Residui');
        legend('Residuo per Iterazione');
	end

end