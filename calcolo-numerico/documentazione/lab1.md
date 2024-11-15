## Numeri in matlab

- **realmin**: Massimo numero rappresentabile
- **realmax**: Minimo numero rappresentabile 
- **esp**: Errore di macchina 
- **pi**: Pi greco
- **+- inf**: + o - infinito

## Formati di visualizzazioni

Si modifica solo la visualizzazione dei numeri con il comando **format**

- **short**
- **long**

## Formati di dati

- **single**: formatta in singola precisione un fp
- **double**: formatta in doppia precisione un fp

## Comandi di arrotondamento

- **fix**: arrotondamento verso 0
- **round**: arrotondamento verso l'intero più vicino
- **floor**: arrotondamento verso -inf
- **cell**: arrotondamento verso +inf

## Output

Il comando **disp** serve per visualizzare una stringa o il valore di
una variabile.

Le stringhe:

- Vanno scritte tra due apostrofi del tipo ’;
- Possono contenere lettere, numeri o caratteri speciali;
- Gli spazi sono caratteri delle stringhe.

Visualizzazione di più dati:

- inserire l’espressione all’interno di parentesi quadre (come
  vosse un vettore)
- convertire ogni parte in stringa separando le varie parti con
  una virgola.

Una possibile alternativa a disp può essere **fprintf**:

- **%e**: printa in formato esponenziale
- **%f**: printa in formato decimale

## Input

esiste il comando input per prendere in input dei dati printando una stringa in precedenza: 

```matlab
a = input('Scrivi un numero intero positivo:');
```

