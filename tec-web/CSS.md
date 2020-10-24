# CSS

## Sintassi

```css
selettore
{
    proprietà: valore;
}
```

## Fogli di stile per differenti dispositivi

```html
<html>
<head>
<title> Esempio con differenti dispositivi </title>
	<link rel=“stylesheet” media=“screen” href=“screen.css” type=“text/css” />
	<link rel=“stylesheet” media=“print” href=“print.css” type=“text/css” />
	<link rel=“stylesheet” media=“aural” href=“screenreader.css” type=“text/css” />
	</head>
	... documento ...
</html>
```

Usare il valore **handheld** per l’attributo media spesso non è sufficiente per identificare tutti i cellulari di nuova generazione, una delle possibili soluzioni potrebbe essere

```html
<link rel="stylesheet" media="handheld, screen and (max-width:480px), only screen and (max-device-width:480px)“ ...>
```

## Procedimento a cascata

1.  Impostazioni personali dell’utente
2.  Impostazioni di stile inline definite dall’autore della pagina
3.  Fogli di stile embedded definiti dall’autore
4.  Fogli di stile esterni definiti dall’autore
5.  Impostazioni di stile predefinite del browser

## Il concetto di importanza

1.  Impostazioni personali dell’utente
2.  Dichiarazioni definite con !important
3.  Impostazioni di stile inline definite dall’autore della pagina
4.  Fogli di stile embedded definiti dall’autore
5.  Fogli di stile esterni definiti dall’autore
6.  Impostazioni di stile predefinite del browser

## Selettori di attributo

```css
elementname[attributename=attributevale]
```

Permettono di selezionare un elemento sulla base del valore di un attributo dato

## Ereditarietà

-   **Ereditarietà**: ogni figlio eredita le impostazioni del padre
-   Se vengono definite più regole con la stessa importanza per uno stesso elemento, l’ultima definita è quella che verrà applicata

## Specificità

La specificità richiede calcoli piuttosto complessi, che a volte possono essere fonte di errore nei browser

<center><b>(num id, num attributi, num tag html)</b></center>

In caso di regole che usano la parola **!important** la specificità viene calcolata su 4 valori, in cui la presenza della parola chiave !important **ha priorità sugli altri**

## Pseudoclassi

- **:link**: link non visitato
- **:visited**: link visitato
- **:active**: link attivo
- **:hover**: vi si trova sopra il mouse
- **:focus**: elemento attivo (tab)
- **:first**: prima pag per media paginati
- **:left**: pagine di sinistra
- **:right**: pagine di destra
- **:first-child**: prima occorrenza
- **:lang**: seleziona una lingua

## Pseudoelementi

- **:first-letter**: prima lettera di un blocco
- **:first-line**: prima riga di un blocco
- **:before**: testo da aggiungere prima
- **:after**: o dopo un elemento

## Sistemi di misura

- **em**: Altezza media del font utilizzato
- **px**: Numero di pixel nello schermo
- **in**: Inch, pollici (1 in = 2,54 cm)
- **cm**: Centimetri
- **mm**: Millimetri
- **pt**: Punti (1 pt = 1/72 pollici)
- **pc**: Pica (1 pc = 12 punti)
- **%**: Valore in percentuale relativo a quello dell’elemento principale

## Font

```css
font: font-style font-variant font-weight font-size/line height font-family
```



-   **font-size**: dimensione
-   **line-height**: interlinea
-   **z-index**: sovvrapposizione
-   **font-style**: corsivo
-   **font-weight**: livelli di grassetto:
    -   **bold**
    -   **normal**
    -   **bolder**
    -   **lighter**
    -   **numeri**
-   **font-variant**: variante maiuscoletto
-   **text-trasform**: **uppercase**, **lowercase**
-   **text-decoration**: decorazione: 
    -   **underline**
    -   **overline**
    -   **line-through**
    -   **none**
-   **color** e **background-color**: colori

### Incorporare font esterni

```css
@font-face{ <descrizione del font> }
```

-   **font-family**: nome da associare al font
-   **src**: local(PERCORSO_LOCALE)/url(URL)
-   **font-style**, **font-weight**, **font-variant** e **font-stretch**

## Immagini di sfondo

```css
selettore { background: background-color background-image background-repeat background-attachment background-position }
```

-   **background-attachment**: stabilisce se l’immagine segue il contenuto nello scroll oppure no
-   **background-repeat**
-   **background-position**

## Box Model

![](/media/filippofantinato/DATA1/UniPD/tec-web/images/box-model.png)

### Padding

```css
selettore { padding: 1em 1em 1em 1em; } /* Senso orario */
```

### Bordi

-   **border-x-width** 
-   **border-style**: stile:
    -   **solid**
    -   **dotted**
    -   **dashed**
-   **border-color**

### Margini

-   Se due o più margini entrano in contatto lungo l’asse verticale, il più piccolo “collassa”, non viene visualizzato.
-   Questo vale anche tra elementi che si contengono, viene visualizzato solo il margine con valore maggiore
-   Per evitare il margin collapsing è necessario definire un bordo o un padding

## Display

Gli elementi si dividono in due gruppi:

-   Di blocco
-   In linea

E' possibile modificare questa caratteristica tramite la proprieta' display

## Position

-   **static**: default
-   **relative**: calcola la posizione del box secondo il flusso normale, poi sposta il box delle proprietà top, bottom, right e left. Questo spostamento non ha effetti sul posizionamento dei box successivi
-   **absolute**: estrae i box dal flusso normale e li posiziona rispetto all’angolo superiore sinistro della pagina. I margini di questi box non collassano con gli altri.
-   **fixed**: si comporta come il posizionamento assoluto, ma i box non scrollano con il resto della pagina

## Float

-   Si sposta a destra o a sinistra rispetto al suo contenitore
-   Si comporta come un box di blocco indipendentemente dalla proprietà display

## Clear

-   Fa in modo che il box che la contiene prenda avvio da sotto il/i box fluttuante

```css
selettore { clear:right/left/both/shape-outside }
```

-   **right/left**: si posiziona dopo tutti i box fluttuanti a destra/sinistra che lo precedono
-   **both** si posiziona dopo tutti i box fluttuanti che lo precedono

