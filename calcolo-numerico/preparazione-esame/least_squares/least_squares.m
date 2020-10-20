function [a] = least_squares(xdata, y, m)

V = vander(xdata);
V = fliplr(V);
V = V(:,1:m+1);

Vt = V';

a = (Vt*V)\(Vt*y);

a = flipud(a);

end

