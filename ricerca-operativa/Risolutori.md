# Introduzione ai risolutori

## Elementi di un modello di Programmazione Matematica

Un modello dichiara le caratteristiche della soluzione ottima in linguaggio matematico

- **Insiemi**: elementi del sistema
- **Parametri**: dati del problema
- **Variabili decisionali o di controllo**: grandezze sulle quali possiamo agire
- **Vincoli**: relazioni matematiche che descrivono le condizioni di ammissibilità delle soluzioni
- **Funzione obiettivo**: e la quantità da massimizzare o minimizzare

## Utilizzo di un solver

Un solver (o risolutore) è un software che riceve in input una descrizione di un problema di ottimizzazione e produce in output la soluzione ottima del modello e informazioni ad essa collegate.

## Ruolo dei modellatori

Un modellatore fornisce un’interfaccia verso un risolutore

## Obiettivi dei modellatori

-   Disporre di un linguaggio semplice:
    -   ad alto livello
    -   simile a quello di modellazione (linguaggio matematico)
    -   formalmente strutturato
    -   possibilità di commenti
-   Consentire la separazione tra implementazione del modello e implementazione delle tecniche di soluzione
-   Dialogare con diversi solver (strutture di I/O standard)
-   Mantenere la separazione tra modello e dati del problema: per cambiare l’istanza basta cambiare i dati, non il modello
-   Linguaggio per script