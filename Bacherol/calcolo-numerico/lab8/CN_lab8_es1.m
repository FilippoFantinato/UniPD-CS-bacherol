clear all;
clc;

INPUT_FILE = 'matrix1.txt';

load(INPUT_FILE);

A = matrix1(:, 1:end-1);
b = matrix1(:, end);

[L, U] = fattorizzazione_LU(A);

y = L\b;
x = U\y;

disp("Soluzione fattorizzazione");
disp(x);

disp("Soluzione normale");
disp(A\b);
