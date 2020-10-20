clear all;
clc;

INPUT_FILE = "dati.txt";

load(INPUT_FILE);

xdata = dati(:,1);
ydata = dati(:,2);

m = 2;

pol = polyfit(xdata, ydata, m);

a = least_squares(xdata, ydata, m);

disp("a = ");
disp(a);
