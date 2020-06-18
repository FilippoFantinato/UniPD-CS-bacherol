clc;
clear all;

x = input("Valore di x: ");
y = input("Valore di y: ");

sumd = x + y;
diffd = x - y;

sums = single(x) + single(y);
diffs = single(x) - single(y);

fprintf("Somma in double precision: %e\n", sumd);
fprintf("Differenza in double precision: %e\n\n", diffd);

fprintf("Somma in single precision: %e\n", sums);
fprintf("Differenza in single precision: %e\n", diffs);
