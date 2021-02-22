set Risorse;
set Domande;

param C {Risorse};
param D {Domande};
param A {Risorse, Domande};

minimize minimo:
    sum{i in C} Var[i]
;
