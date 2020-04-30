# Array

Tutte le variabili di matlab sono array

## Scalari

Sono delle variabili a valore singolo, quindi un array 1x1

## Square notation

Si possono creare array con elementi multipli usando le parentesi quadre

```matlab
x = [3 5]
```

Si possono separare i numero o con lo spazio o con la virgola

Per creare più colonne si devono separare le righe con il pungo e virgola

```matlab
x = [ 
		3 5 7;
        7, 8, 9;
        8, 8, 8
	]
```

## : notation

Per creare array con sequenze di numeri in modo automatico, esiste la notazione : utilizzabile in questo modo

```matlab
x = 1:4 # Crea un row vector contenente i numeri da 1 a 4
x = 1:4:20 # Crea un row vector contenente i numeri da 1 a 20 con uno spacing di 4: 1 4 8...
```

