

if a == 0
    if b == 0
        if c == 0
            disp("Equazione indeterminata");
        else
            disp("Equazione impossibile");
        end
    else
        x1 = -c/b;
        fprintf("x1=%e\n", x1);
    end
else
    delta = b^2 - 4*a*c;
    
    if delta < 0
        disp("ERRORE: discriminante negativo");
    elseif delta == 0
        x1 = -b/(2*a);
        x2 = x1;
        
        fprintf("x1=x2=%e\n", x1);
    else
        if b == 0
            if a * c < 0
                disp("Errore: a e c segno discorde");
            else
                x1 = sqrt(c/a);
                x2 = -sqrt(c/a);
                fprintf("x1=%e\n", x1);
                fprintf("x2=%e\n", x2);
            end
        else
            x1 = (-b - sign(b)*delta)/(2*a);
            x2 = c/(a*x1);
            
            fprintf("x1=%e\n", x1);
            fprintf("x2=%e\n", x2);
        end
    end     
end
