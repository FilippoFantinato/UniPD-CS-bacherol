function [] = tabella(xv, output_file)

tab = [(1:length(xv)); xv];

fprintf("Tabella: \n");
fprintf("n\txv\n");
fprintf("%d\t%e\n", tab);

tabt = tab';

save(output_file, '-ascii', 'tabt');

end
