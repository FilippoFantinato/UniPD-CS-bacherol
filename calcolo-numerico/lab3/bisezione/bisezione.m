function [xv, fxv, n] = bisezione(f, a, b, toll, nmax)
% BISEZIONE Metodo di Bisezione
%
% Uso :
% [ xv , fxv , n ] = bisezione ( f, a, b, toll, nmax )
%
% Dati di ingresso :
% f : funzione
% a : estremo sinistro
% b : estremo destro
% toll : tolleranza rischietsa sul valore della funzione
% nmax : massimo indice dell’ iterazione permesso
%
% Dati di uscita :
% xv : vettore contenente le iterazioni
% fxv : vettore contenenti i corrispodenti residui
% n : indice dell’ iterazione finale calcolata

xv = [];
fxv = [];
n = 0;

res = toll + 1;
% fa = f(a);

while res > toll && n < nmax
	c = (a + b) / 2;

	fc = f(c);
    
    res = abs(fc);

	% s = fa * fc;
    s = f(a) * fc;

	xv = [xv c];
	fxv = [fxv res];

	if s > 0
		a = c;
        % fa = fc;
	elseif s < 0
		b = c;
	else
		break;
	end

	n = n + 1;
end

end
