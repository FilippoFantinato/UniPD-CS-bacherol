function [int, Q, flag] = simpson_adattativa(f,a,b,m,toll,nmax)

TOLL = 10^-15;

Q = quadl(f, a, b, TOLL);

En = toll+1;
n = 1;
int = [simpson(f, a, b, m)];

while n < nmax && En >= toll
    n = n + 1;
    m = 2*m;
    
    I = simpson(f, a, b, m);
    int = [int I];
    En = abs(int(n) - int(n-1));
end

if n == nmax
    flag = 1;
else
    flag = 0;
end

end
