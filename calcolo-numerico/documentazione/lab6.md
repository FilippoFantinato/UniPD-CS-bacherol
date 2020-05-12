# Approssimazione

Voglio trovare un polinomio p(x) di grado m << N t.c. sia minimo l'errore commesso
$$
\sum_{i=1}^N |p(x_i) - y_i|^2
$$
Si usano le funzioni polyfit e polyval, ma con un grado del polinomio m << N.

# I/O

## Save

Salva il workspace attuale in un file con estensione .mat.

Per aggiungere al file salvato altre variabili, si usa l'opzione append.

```matlab
save('nome_file.mat', ['variabili da salvare'], '-append');
```



## Load

Serve per caricare un workspace salvato in precedenza

```matlab
load('nome_file.mat');
```

