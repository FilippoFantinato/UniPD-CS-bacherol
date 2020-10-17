function [xv, fxv, n] = newton(f, f1, x0, toll, nmax)
% NEWTON Metodo di Newton
%
% [xv, fxv, n] = newton( f, f1, x0, toll, nmax)
%
% Dati di ingresso:
% 	f: 			funzione
%	f1: 		derivata prima
%	x0: 		valore iniziale
%	toll: 		tolleranza richiesta per il valore assoluto della differenza di due iterate successive
% 	nmax: 		massimo numero di iterazioni permesse
%
% Dati di uscita:
%	xv: 		vettore contenente le ascisse delle iterazioni
%	fxv:		vettore contenente i corrispondenti residui (f(xv)) 
%	n:			numero di iterazioni

n = 1;
difference = 2 * toll;

xv = [x0];
fxv = [f(x0)];

while abs(difference) >= toll && n < nmax
	current_xvalue = xv(n);

	if f1(current_xvalue) == 0
		break;
	else
		difference = -f(current_xvalue) / f1(current_xvalue);
		xv(n + 1) = current_xvalue + difference;

		fxv(n + 1) = f(xv(n + 1));

		n = n + 1;
	end
end

end
