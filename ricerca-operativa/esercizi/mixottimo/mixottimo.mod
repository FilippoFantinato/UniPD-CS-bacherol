set Prodotti;
set Risorse;

param P{Prodotti};
param Q{Risorse};
param A{Prodotti, Risorse};
param MaxProduzione;

var x{Prodotti} >=0, <=MaxProduzione;

maximize profitto: sum{i in Prodotti} P[i]*x[i];

s.t. disponib{j in Risorse}: sum{i in Prodotti} A[i, j]*x[i] <= Q[j];
