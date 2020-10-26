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