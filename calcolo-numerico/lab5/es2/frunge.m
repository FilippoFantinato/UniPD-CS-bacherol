function ydata = frunge(xdata)

ydata = [ ];

runge = @(x) 1/(1+x^2);

for x = xdata
    ydata = [ydata runge(x)];
end

end
