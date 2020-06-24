clc;
clear all;

% Costante
N_MAX = 100;
TOLL = 10^-8;

% f = @(x) sqrt(x + 1) - exp(-x);
f = @(x) exp(x) - 5 + x^2;
% f = @(x) 3*x - cos(x);
% f = @(x) x + log(x);
% f = @(x) sin(x) - x^2/2;

% a = -0.5; b = 1;
a = -2; b = 2;
% a = -1; b = 1;
% a = 0.5; b = 1;
% a = -0.5; b = 1;

% Visualizzazione dati inseriti
disp("Funzione inserita: ");
disp(f);
fprintf("Estremo a = %d\n", a);
fprintf("Estremo b = %d\n", b);
fprintf("Tolleranza: %e\n", TOLL);
fprintf("Numero massimo di iterazioni %d\n\n", N_MAX);

if f(a)*f(b) > 0
    disp("ERROR: Non cambia segno agli estremi");
else
    [xv, fxv, n] = bisezione(f, a, b, N_MAX, TOLL);
    
    semilogy(1:n, abs(fxv), 'r-o', "LineWidth", 2, "MarkerEdgeColor", "b", "MarkerFaceColor", "b");
    
%     hold on;
    title(strcat("f: ", func2str(f), " | ", "a=", num2str(a), " b=", num2str(b)));
    legend("bisezione");
    xlabel("iterazione");
    xlabel("residuo");
    
%     hold off;
    
    if(n > N_MAX)
        disp("WARNING: è stato superato il numero massimo di iterazioni");
    end
    
    fprintf("Zero: %e\n", xv(end));
    fprintf("Numero di iterazioni: %d\n", n);
end


