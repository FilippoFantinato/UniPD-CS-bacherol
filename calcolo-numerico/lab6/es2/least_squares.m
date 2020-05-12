function a = least_squares(xdata, ydata, m)
%LEAST_SQUARES calcolo dell’approssimazione a i minimi quadrati
% Dati di ingresso
%   xdata : ascisse dei punti campionati
%   ydata : ordinate dei punti campionati
%   m: grado del polinomio approssimante
%
% Dati in uscita:
%   a : vettore dei coefficenti del polinomio approssimante ai minimi
%       quadrati

a = [];

% Calcolo la matrice di Vandermonde NxN e ne faccio il "flip" orizionale
V = vander(xdata);
V = fliplr(V);

% Riduco la matrice di Vandermonde a Nx(m+1)
V = V(:,1:m+1);

% Sistema da risolvere (V^t * V)a = V^t * ydata
% chiamo K = V^t * V
% chiamo b = V^t * ydata
% calcolo la matrice K = V^t * V
VT = V';
K = VT * V;

% Calcolo il vettore dei termini noti b = V^t * ydata
b = VT * ydata;

% Risolvo il sistema
a = K\b;

% Inverto l'ordine dei coefficenti con flipud
a = flipud(a);

end

