function yh = horner(P, x)
% HORNER regola di Horner
% Calcola il valore del polinomio in x
% Dato il vettore dei coefficienti P
% Dati di ingresso
%   P: vettore dei coefficienti del polinomio ordinati in ordine decrescente
%       P(1) è il coefficiente che moltiplica x^n
%       P(end) è il termine noto
%   x: Punti su cui voglio valutare il polinomio
% Dati in uscita:
%   yh: Polinomio

yh = [ ];

for value = x
    y = P(1);
    
    for i = 2:length(P)
        y = y * value + P(i);
    end
    
    yh = [yh y];
end

end
