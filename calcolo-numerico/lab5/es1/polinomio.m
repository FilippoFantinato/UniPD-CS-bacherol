function ypol = polinomio(P, x)
% POLINOMIO
%   Calcola il valore di polinomio in x
%   Dato il vettore dei coefficienti P
%   secondo la forma ypol = a0 + sum_i=1^n ai x^i
%
% Dati di ingresso
%   P: vettore dei coefficienti del polinomio ordinati in ordine decrescente
%       P(1) è il coefficiente che moltiplica x^n
%       P(end) è il termine noto
%   x : Punti su cui voglio valutare il polinomio
% Dati in uscita:
%   ypol: Polinomio

ypol = [ ];

lengthP = length(P);

for value = x
    y = P(end);
    
    for i = 1:(lengthP-1)
        y = y + value^(lengthP-i)*P(i);
    end
    
    ypol = [ypol y];
end

end
