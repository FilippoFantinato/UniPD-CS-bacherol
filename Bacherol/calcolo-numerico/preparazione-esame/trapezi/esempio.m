clear all;
clc;

OUTPUT_FILE = "tabella.txt";

f = @(x) x.^(11/2);
a = 0;
b = 1;
toll = 10^-8;

[I, Q, flag] = trapezi_adattativa(f, a, b, toll);

En = abs(I - Q)/abs(Q);

semilogy(1:length(En), En, "ro-", "LineWidth", 2, "MarkerFaceColor", "b", "MarkerEdgeColor", "b");
legend("Errori relativi");
xlabel("Iterazioni");
ylabel("Errori relativi");

fid = fopen(OUTPUT_FILE, "wb");
fprintf(fid, "%d\t\t%1.15e\n", [1:length(I); I]);

fclose(fid);
