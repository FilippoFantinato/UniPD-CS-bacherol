function [xv,fxv,n,flag] = halley(f,f1,f2,x0,toll,nmax)

xv = [x0];
fxv = [f(x0)];
n = 1;

flag = 0;

diff = toll + 1;

while n < nmax && abs(diff) >= toll
    xn = xv(n);
    
    den = 2*f1(xn)^2 - f(xn)*f2(xn);
    
    if den == 0
        flag = 1;
    else
        diff = (2*f(xn)*f1(xn))/den;
        xv(n+1) = xn - diff;
        
        fxv(n+1) = f(xv(n+1));
        
        n = n + 1;
    end
end

if n >= nmax
    flag = 2;
end

end
