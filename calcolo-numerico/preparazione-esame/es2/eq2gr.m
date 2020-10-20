coefficenti = [
                1, 10^-5, -2*10^-10;
                -10^-7, 1+10^-14, -10^-7;
                10^-10, -1, 10^-10
              ];
          
for i = 1:length(coefficenti)
              
    a = coefficenti(i, 1);
    b = coefficenti(i, 2);
    c = coefficenti(i, 3);

    delta = b^2 - 4*a*c;

    fprintf("a = %e, b = %e, c = %e\n", a, b, c);
    
    if(a ~= 0 && b ~= 0 && c ~= 0)
        if(delta < 0)
            disp("ERROR: delta negativo");
        else
            x1 = (-b - sqrt(delta))/(2*a);

            if(delta == 0)
                fprintf("x1=x2=%e\n", x1);
            else
               x2 = (-b + sqrt(delta))/(2*a);
               fprintf("x1=%e\n", x1);
               fprintf("x2=%e\n", x2);
            end
        end
        fprintf("\n");
    end
end
