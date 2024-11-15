# Dichiarazione variabili
var xL;
var xP;

# Modello
maximize resa: 3000*xL + 5000*xP;

s.t. ettari: xL + xP <= 12;
s.t. semi: 7*xL <= 70;
s.t. tuberi: 3*xP <= 18;
s.t. conc: 10*xL + 20*xP <= 145;
s.t. dominio1: xL >= 0;
s.t. dominio2: xP >= 0;
