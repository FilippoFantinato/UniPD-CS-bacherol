format long e

a = [123456789.0 1234.56789 3.34567891 33456789100];

% for i = 1:4
%     v = input('Inserisci un numero: ');
%     a = [a v];
% end

disp(a);

for i = a
    ad = i;
    as = single(i);
    epsa = abs(ad - as);
    epsr = abs(ad - as) / abs(ad);
    
    fprintf('ad: %f\n', ad);
    fprintf('as: %f\n', as);
    fprintf('epsa: %f\n', epsa);
    fprintf('epsr: %f\n', epsr);
end
