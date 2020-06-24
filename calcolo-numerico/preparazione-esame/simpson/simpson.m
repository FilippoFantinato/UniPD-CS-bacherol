function int = simpson(f, a, b, m)

if rem(m,2) ~= 0
    error("L'integrale non può essere calcolato");
%     int = nan;
else
    H = (b-a)/m;
    h = H/2;

    x = a:h:b;

    int = 0;

    for i=1:2:2*m-1
        int = int + (f(x(i)) + 4*f(x(i+1)) + f(x(i+2)));
    end

    int = int*(h/3);

end

end
