#DICHIARAZIONE INSIEMI
set Prodotti;
set Risorse;
#DICHIARAZIONE PARAMETRI
param maxNumProd; # massimo numero prodotti
param P {Prodotti}; # profitto unitario
param Q {Risorse}; # disponibilità risorsa
param A {Prodotti,Risorse};

# risorsa per unità di pr.

var x {i in Prodotti} >=0 , <= maxNumProd[i] integer;
maximize profitto: sum {i in Prodotti} P[i]*x[i];
subject to disponib {j in Risorse}:
	sum {i in Prodotti} A[i,j]*x[i] <= Q[j];
	