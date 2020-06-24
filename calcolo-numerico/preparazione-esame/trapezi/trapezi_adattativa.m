function [I, Q, flag] = trapezi_adattativa(f, a, b, toll)

NMAX = 100;
TOL = 10^-15;

int = trapezi_composta(f, a, b, 1);
I = [int];
i = 1;

Q = quadl(f, a, b, TOL);

En = toll + 1;

flag = 0;

while i < NMAX && En >= toll
    
    i = i + 1;
    m = 2^(i-1);
    int = trapezi_composta(f, a, b, m);
    I = [I int];
    
    En = abs(I(i)-I(i-1));
end

if En < toll
    flag = 1;
end

end

