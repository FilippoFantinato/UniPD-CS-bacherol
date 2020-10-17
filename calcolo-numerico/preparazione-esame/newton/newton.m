function [xv, fxv, n] = newton(f, f1, x0, nmax, toll)

xv = [x0];
fxv = [f(x0)];
n = 1;
diff = toll + 1;

while (abs(diff) >= toll) && (n < nmax)
    if xv(n) == 0
        break;
    else
        diff = f(xv(n))/f1(xv(n));
        xv(n + 1) = xv(n) - diff;
        fxv(n + 1) = f(xv(n + 1));
    end
    
    n = n + 1;
end

end