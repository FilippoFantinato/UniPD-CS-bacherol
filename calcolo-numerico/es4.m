x = linspace(-0.5, 1);

f1 = @(t) sqrt(t + 1) - exp(-t);

y = f1(x);
plot(x, y);

axis([-5 5 -5 5]);

axis normal;

% x = linspace(-2, 2);

% f2 = @(t) exp(t) - 5 + t^2;

% x = linspace(-1, 1);
% x = linspace(0.5, 1);
% x = linspace(-0.5, 1);


% x = linspace(-2, 2);

% f2 = @(t) exp(t) - 5 + t^2;

% x = linspace(-1, 1);
% x = linspace(0.5, 1);
% x = linspace(-0.5, 1);