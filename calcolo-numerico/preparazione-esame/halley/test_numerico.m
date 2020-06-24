clear all;
clc;

f = @(x) x^2 - 1 + exp(-x);
f1 = @(x) 2*x - exp(-x);
f2 = @(x) 2 + exp(-x);

x0 = 0.5;
toll = 10^(-14);
nmax = 1000;

[xv, fxv, n, flag] = halley(f, f1, f2, x0, toll, nmax);

fprintf("Iterate\txv\t\t|fxv|\n");
fprintf("%d\t%e\t%e\n", [1:n; xv; abs(fxv)]);

S = [];

for i = 2:n
    S = [S (xv(i) - xv(i-1))];
end

semilogy(1:n-1, S, "ko-", "MarkerFaceColor", "r", "MarkerEdgeColor", "r");
