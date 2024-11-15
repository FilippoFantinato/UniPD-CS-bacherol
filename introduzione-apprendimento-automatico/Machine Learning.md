# Machine Learning

## Definizione

Un computer si dice che sta imparando dall'esperienza E rispettando alcune classi di compiti T e con un certo valore di performance P, se la sua performance ai compiti T migliora con l'esperienza E.

### Esempio

Classificazione di frutti

* **Come l'oggetto viene rappresentato**: si individuano le caratteristiche di un oggetto, anche dette **feature**, che vengono utilizzate durante la decisione;
* **Task**: individuazione della classe dei frutti;
* **Performance**: viene definita dall'accuratezza (successo) e dipende dal task;
* **Experience**: sono i dati che vengono forniti e definisce l'algoritmo di apprendimento automatico

## I principali paradigmi di apprendimento

### Supervised Learning

Ogni dato dell'esperienza viene esperesso da ogni coppia (X, Y), dove X è un informazione e Y l'informazione a cui deve arrivare.Quello da definire è la funzione H che riesca a mappare da X a Y in maniera predittiva. I dati devono essere forniti da un esperto (o un insegnante) che fornisca questi dati.

La natura di Y dipende se sia un valore continuo (predizione) o un valore discreto (problema di classificazione).

### Unsupervised Learning

Rispetto all'apprendimento supervisionato, l'apprendimento non supervisionato non presenta un esperto e si cerca di trovare una regolarità nei dati X.

### Reinforcement Learning

Sono presenti due attori principali: l'ambiente esterno e un agente che cambia lo stato di un operatore in base all'ambiente esterno. Il compito dell'agente è di massimizzare il premio dato da una funzione di reward.

## Supervised Learning

### Ingredienti fondamentali

* D: training data X (sottoinsieme di tutti i possibili dati);
* H: spazio di ipotesi da cui dedurre h;
* h: algoritmo dedotto da H

### Inductuve/Learning Bias

Qualsiasi decisione che si compie viene caraterizzata come problema di Inductive Bias

Ci sono due tipi di bias:

* Restrittivo: limiti nello spazio delle ipotesi;
* Preferenza: preferenza negli spazi delle ipotesi.



