function [xv, fxv, n] = bisezione(f, a, b, nmax, toll)

res = toll + 1;
n = 0;
xv = [];
fxv = [];

while res > toll && n < nmax
    
    c = (a + b) / 2;
    
    fc = f(c);
    
    xv = [xv c];
    fxv = [fxv fc];
    
    res = abs(fc);
      
    if fc == 0
        break;
    elseif f(a)*fc < 0
        b = c;
    elseif f(b)*fc < 0
        a = c;
    end
    
    n = n + 1;
    
end

end
