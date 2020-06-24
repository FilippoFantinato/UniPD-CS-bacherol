clc;
clear all;

% Costante
N_MAX = 100;
TOLL = 10^-8;
X0 = 2;

% f = @(x) sqrt(x + 1) - exp(-x); f1 = 1/(2*sqrt(x + 1)) + exp(-x);
f = @(x) exp(x) - 5 + x^2; f1 = @(x) exp(x) + 2*x;
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
    [xv_b, fxv_b, n_b] = bisezione(f, a, b, N_MAX, TOLL);
    [xv_n, fxv_n, n_n] = newton(f, f1, X0, N_MAX, TOLL);
    
    semilogy(1:n_b, abs(fxv_b), 'r-o', "LineWidth", 2, "MarkerEdgeColor", "b", "MarkerFaceColor", "b");
    
    hold on;
    
    semilogy(1:n_n, abs(fxv_n), 'g-o', "LineWidth", 2, "MarkerEdgeColor", "y", "MarkerFaceColor", "y");
    
    title(strcat("f: ", func2str(f), " | ", "a=", num2str(a), " b=", num2str(b)));
    legend("Bisezione", "Newton");
    xlabel("iterazione");
    xlabel("residuo");
    
    hold off;
    
    if(n_b > N_MAX)
        disp("WARNING: bisezione ha superato il numero massimo di iterazioni");
    end
    
    if(n_n > N_MAX)
        disp("WARNING: newton ha superato il numero massimo di iterazioni");
    end

    fprintf("Bisezione zero: %e\n", xv_b(end));
    fprintf("Bisezione numero di iterazioni: %d\n", n_b);

    fprintf("Newton zero: %e\n", xv_n(end));
    fprintf("Newton numero di iterazioni: %d\n", n_n);
end


