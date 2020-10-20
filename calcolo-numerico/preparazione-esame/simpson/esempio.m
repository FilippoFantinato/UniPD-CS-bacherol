clear all;
clc;

f = @(x) x.^(11/2);
a = 0;
b = 1;
m = 2;
toll = 10^-8;
nmax = 20;

[int, Q, flag] = simpson_adattativa(f, a, b, m, toll, nmax);

if flag == 0
    En = abs(int - Q);

    semilogy(1:length(En), En, 'ro-', "LineWidth", 2, "MarkerFaceColor", "b", "MarkerEdgeColor", "b");
    legend("Errore assoluto");
    xlabel("Iterazione");
    ylabel("Errore assoluto");
    
else
    disp("ERROR: Sono state superate le iterazioni massime");
end
