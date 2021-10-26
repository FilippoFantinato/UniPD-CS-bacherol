# CSS 3

## Selettori di attributo

-   **elem[attr]**: applica la regola ai tag elem che hanno un attributo attr
-   **elem[attr=“value”]**: applica la regola ai tag elem che hanno un attributo attr con valore value
-   **elem[attr~=“value”]**: applica la regola ai tag elem che hanno un attributo attr uguale a una lista di parole separate da spazi che contiene la sottostringa value
-   **elem[attr|=“value”]**: applica la regola ai tag elem che hanno un attributo attr uguale a una lista di parole separate da trattini. La prima parola deve essere uguale a value
-   **elem[attr*=“value”]**: applica la regola ai tag elem che hanno un attributo attr che contiene la sottostringa value
-   **elem[attr$=“value”]**: applica la regola ai tag elem che hanno un attributo attr che termina con la sottostringa value

## Pseudoclassi

-   **:target** agisce sull’ancora di un link, ovvero sulla destinazione del link, alla sua attivazione
-   **:enable**, **:disable**, **:checked** agiscono sulle componenti delle form quando si trovano nei rispettivi stati
-   **:not(selettore)**
-   **default**

## Selettori di posizione

- **:nth-child(n)** elemento che è l’n-esimo figlio di suo padre
- **li:nth-child(3)** tutti i punti elenco che si trovano in terza posizione (terzo figlio di un ul)
- **:nth-last-child(n)** elemento che è l’n-esimo figlio di suo padre cominciando a contare dall’ultimo
- **:nth-of-type(n)** elemento (ex: <p>) che è l’n-esimo figlio dello stesso tipo (ex:l’n-esimo figlio <p>) di suo padre
- **:nth-last-of-type(n)** elemento (ex: <p>) che è l’n-esimo figlio dello stesso tipo (ex:l’n-esimo figlio <p>) di suo padre cominciando a contare dall’ultimo
- **:only-child** elemento che è l’unico figlio di suo padre
- **:only-of-type** elemento che è l’unico figlio di suo padre di quel tipo

## Variabili

-   Si definiscono con **--nomeVariabile**
-   Si usano con la funzione **var(--nomeVariabile)**

### Globali

```css
:root
{
	--coloreTesto: black;
	--coloreSfondo: white;
	--link: blue;
	--linkVisitati: purple;
}
```

### Locali

Come globali, ma non dentro **:root**

## RGBA & Opacity

CSS3 definisce un nuovo modello di colori, RGBA,che permette di aggiungere il canale Alpha per l’opacità espressa con valore compreso tra 0 e 1 dove 1 vuol dire completamente opaco e 0 indica la totale trasparenza.

```css
.semiTrasparente
{
	color: rgba(0, 0, 0, 0.5);
}

.elem
{
	opacity: 0.5;
}
```

## Ombreggiature

Per l’ombreggiatura del testo è possibile specificare direzione, raggio della sfumatura e colore:

```css
p {
	text-shadow: 10px 10px 10px #999;
}
```

L’ombreggiatura di un elemento ha la stessa sintassi di quella del testo e vi aggiunge l’ingrandimento:

```css
.conOmbra
{
	box-shadow: 10px 10px 10px 5px rgba(999, 999, 999, 1);
}
```

## Inserire più immagini di sfondo

Lo standard CSS3 permette di inserire più immagini di sfondo tramite la proprietà background, separando i valori con una virgola

## Transizioni

- **transition-property**: la proprietà a cui applicare la transizione
- **transition-duration**: durata
- **transition-timing-function**: funzione che modella l’andamento della transizione (ease, linear, ease-in, ease-out, ease-in-out, cubic-bezier)

### Esempio

```css
selettore
{
    -webkit-transition: background 3s linear;
	-moz-transition: background 3s linear;
	-o-transition: background 3s linear;
	transition: background 3s linear;
}
```

## Media queries

Permette di segnalare dei breakpoint e anche sul tipo di dispositivo

```css
@media screen and (min-width: 1024px)
{
	.classe
    {
		width: 960px;
	}
}

@media print and (max-width: 768px)
{
	.classe
    {
		width: 100%;
	}
}
```

## Colonne per il testo

```css
.classe {
	column-count: 3;
    column-width: 30%;
}
```

## Display Table

-   Si divide la lista in tante liste quante sono le righe
-   Si definisce una classe per le liste che identificano le righe
-   Si aggiunge un contenitore che racchiuda tutte le liste

```html
<div class="wrapper">
    <ul class="cards">
        <li> <h2>Card 1</h2> <p>...</p> </li>
        <li> <h2>Card 2</h2> <p>...</p> </li> ...
    </ul>
    <ul class="cards">
        <li> <h2>Card 1</h2> <p>...</p> </li>
        <li> <h2>Card 2</h2> <p>...</p> </li> ...
    </ul>
</div>

<style>
.wrapper
{
	display: table;
	border-spacing: 20px;
	margin: -20px;
}

.cards
{
	margin: 0;
	padding: 0;
	list-style: none;
	display: table-row;
}

.cards li 
{
	display: table-cell;
	vertical-align: center;
	background-color: #fff0f6;
	border: 1px solid #fcc2d7;
	padding: 10px;
	border-radius: 5px;
}
</style>
```

## Flexbox

### Proprietà

- **flex-direction**: direzione degli elementi flex, per righe o per colonne
- **flex-wrap**: permette di andare a capo
- **flex-basis**: definisce la larghezza (se flex-direction:row) o l’altezza (se flex-direction:column) di un elemento. Se 0 lo spazio viene distribuito a seconda di flex-grow
- **flex-grow**: se uguale a >=1 l’elemento può crescere per coprire lo spazio rimasto
- **flex-shrink**: se uguale a >=1 l’elemento può occupare meno spazio di quello definito inizialmente
- **flex**: proprietà scorciatoia flex:flex-grow flex-shrink flex-basis

### Allineamento

- **align-items**: dove si allineano i vari elementi (align-self è riferito solo a sè stesso)
- **flex-start**: top del contenitore
- **flex-end**: bottom del contenitore center
- **stretch**: riempie il contenitore
- **align-content**: richiede flex-wrap: wrap e agisce sull’asse y quando il contenitore è più alto dello spazio richiesto dal contenuto. Valore di default: stretch

## Grid

L’unità di misura utilizzata è **fr**, un’unità di misura creata appositamente per le griglie perché si adatta al layout. È definita come una frazione dello spazio disponibile.

### Proprietà

- **grid-template-columns(/rows/areas)**: permette di definire template per righe/colonne/aree bidimensionali. In pratica si definisce il numero di righe/colonne
- **align-items**, **align-self**, **justify-items**, **justify-self**: (valore di default stretch)
- **repeat**, **auto-fill** (numero di colonne in base allo spazio da occupare), **auto-fit** (espande le colonne per riempire tutta la riga)

