% EQ2GR Script per la risoluzione di un’equazione
% 		di secondo grado ( solo soluzioni reali )
% 		con i coefficienti a, b e c non nulli
% 		FORMULE STATIBILI

% Settare il formato di visualizzazione

a = input('a = ');
b = input('b = ');
c = input('c = ');

if a ~= 0 && b ~= 0 && c ~= 0
	delta = b^2 -4*a*c;

	if delta < 0
		fprintf('Non ha soluzioni reali\n');
	elseif delta == 0
		x1 = -b / 2*a;
		fprintf('x1 = x2 = %e\n', x1);
	else
		x1 = (-b - sign(b)*sqrt(delta)) / 2*a;
		x2 = c / (a*x1);
		fprintf('x1 = %e\n', x1);
		fprintf('x2 = %e\n', x2);
	end
else
	fprintf('Non tutti i coefficienti sono 0\n');
end

