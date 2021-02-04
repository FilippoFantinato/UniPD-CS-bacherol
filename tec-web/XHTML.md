# XHTML

## Sintassi

-   I tag e gli attributi sono case sensitive (tutto in minuscolo)
-   I tag devono sempre essere chiusi (anche se sono vuoti)
-   I tag devono essere aperti e chiusi nell’ordine corretto
-   L’ordine con cui si inseriscono gli attributi è irrilevante
-   I valori degli attributi vanno riportati tra “virgolette doppie”
-   Tutti gli attributi devono avere un valore
-   Un elemento in linea non può contenere un elemento di blocco

Viene ignorato: 

-   Le interruzioni di linea non identificate con \<br/> e non
    contenute in un tag \<pre>
-   Tabulazioni e spazi multipli
-   Tag \<p> nidificati
-   Tag sconosciuti
-   Commenti \<!-- -->

## Struttura

```html
<!DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="it" lang="it">
    <head>
    	<title>Titolo</title>
    </head>
    <body>
        
    </body>
</html>
```

## Caratteri speciali

| spazio | \&nbsp; |
| :----: | :-----: |
|        |         |

## Tag

### Head

-   **title** (obbligatorio), link, meta, base, style e script
-   **link** definisce un collegamento ad una risorsa esterna (CSS,
    shortcut icon, etc). Gli attributi più comuni sono:
    -   **rel**: sta per relazione e i valori più usati sono **stylesheet** e **shortcut icon**
    -   **href**

### Meta

La sezione head contiene una serie di comandi, chiamati MetaComandi, che non producono alcuna variazione visiva sulla pagina, ma sono indispensabili per altre attività quali la validazione e la lettura da parte dei motori di ricerca.

I metacomandi inseriscono informazioni aggiuntive sul contenuto del documento che si sta creando, come ad esempio l’autore.

Ci sono due tipi di tag meta:

-   **http-equiv**
-   **name** 

#### http-equiv

L’informazione viene processata come se fosse presente in un header di risposta proveniente da un server HTTP, quindi prima del documento

```html
<meta http-equiv=“refresh” content=“15” />
<meta http-equiv=“refresh” content=“1;URL=nuovaURL” />
<meta http-equiv=“expires” content=“5” />
```

#### name

Inseriscono informazioni riguardanti il documento ed è possibile creare valori propri (ex. suggeriti dai motori di ricerca).

I valori attuali sono:

-   **description**: breve descrizione dei contenuti della pagina web. È particolarmente utile quando la pagina contiene poco testo
-   **keywords**: lista di parole chiavi separate da una virgola
-   **copyright**, **author**
-   **robots**: utilizzato per prevenire l’indicizzazione di una pagina. Valori: index, noindex, follow, nofollow (i link della pagina), all, none
-   **rating**: classificazione del contenuto

### Body

La sezione body contiene tutti i tag che descrivono la struttura del documento: non devono essere usati elementi relativi alla presentazione visuale.

### Attributi comuni

#### Core

class, id, title e style

#### i18n

Gli attributi internationalization (i18n) sono dir (direzione, ltr o rtl) e xml:lang

#### Evento

Gli attributi evento rappresentano gli eventi JavaScript

#### Id vs class

class definisce un gruppo di appartenenza mentre id identifica un elemento in modo univoco

Dare un id ad un elemento permette di usarlo:

-   come selettore in un foglio di stile
-   all’interno di uno script
-   come ancora di destinazione di un link
-   come strumento generico nel trattamento dei dati

Un id deve cominciare con una lettera o con il carattere “_”.

### Contenitore generico

L'elemento **\<div>** è un contenitore generico per l'associazione con fogli di style e crea un nuovo blocco. Tutti gli attributi e le associazioni applicate al tag div saranno estese a tutto il blocco di codice interessato.

### Contenitore generico in linea

L'elemento \<span> non ha alcuna caratteristica se non quella di fare da supporto per gli stili. Diversamente da div, è un elemento in linea.

### Intestazione

Esistono sei livelli di intestazione: h1, h2, h3, h4, h5, h6.

Si devono utilizzare rispettando l’ordine e pensando alla struttura del documento e non a come vengono visualizzati di default.

```html
<h1>Heading 1 (h1)</h1>
<h2>Heading 2 (h2)</h2>
<h3>Heading 3 (h3)</h3>
<h4>Heading 4 (h4)</h4>
<h5>Heading 5 (h5)</h5>
<h6>Heading 6 (h6)</h6>
```

### Formattazione del Testo

-   **p**: in questo modo si formano dei paragrafi
-   **br**: all’interno dello stesso paragrafo è possibile andare a capo con il tag \<**br** />
-   **em**: italico
-   **strong**: grassetto

### Citazione

-   **blockquote**: introduce un’ampia citazione che occupa
    un’intero blocco.
-   **q**: introduce una citazione più ristretta in linea.
-   **cite**: La fonte può essere indicata tramite gli attributi cite
    (obbligatoriamente un URI) o title, oppure con il tag <cite>

### Abbreviazioni, acronimi, indirizzi

-   **abbr**: indica le abbreviazioni
-   **acronym**: indica gli acronimi
-   **address**: identifica un indirizzo

### Altri tag per l’inserimento di testo particolare

-   **code**: permette di inserire del codice all’interno di HTML
-   **var**: identifica delle variabili in un codice
-   **samp**: identifica un particolare output di un programma
-   **pre**: permette di inserire testo preformattato, dove spazi,
    tabulazioni e a capo hanno un valore
-   **ins**: identifica un inserimento redazionale. Solitamente è
    visualizzato sottolineato
-   **del**: identifica una cancellazione redazionale. Solitamente è
    visualizzata barrata

### Elenchi non ordinati

Elenchi puntati da utilizzare quando vogliamo dei punti per il nostro elenco, senza un ordine ben preciso.
**\<ul>** ogni elemento di lista è compreso all'interno di un elemento **\<li>**.

### Elenchi ordinati

Elenchi numerati da utilizzare quando vogliamo dei punti che abbiano una gerarchia o un ordine ben preciso.

**\<ol>** ogni elemento di lista è compreso all'interno di un elemento **\<li>** (List Item).

### Elenchi di definizioni

Elenchi in cui non si utilizza alcun tipo di punto, utili soprattutto per definire dei termini.

**\<dl>** il termine da definire è indicato dall'elemento **\<dt>** e la definizione dall'elemento **\<dd>**. 

Ci possono essere più **\<dd>** per un unico **\<dt>** e viceversa.

### Immagini

Attributi:

-   **alt**: testo alternativo
-   **longdesc**: URI ad una pagina con una descrizione
    dell’immagine 
-   **align**, hspace, **vspace**

```html
<img src="" alt=""/>
```

### Link

Sorgente del link può essere un pezzo di testo (hot word) ma anche elementi più complessi come le immagini (thumbnail). Destinazione del link può essere una pagina o una sua parte.

È molto importante che i link siano accessibili anche agli utenti non in grado di utilizzare il mouse **accesskey** e **tabindex** indicano rispettivamente un carattere per portare il focus sul link e l’ordine di tabulazione.

Si possono anche inserire dei link non ipertestuali:

-   **mailto**
-   **ftp**
-   **file**
-   **news:newsgroup**

```html
<a href="link">Testo</a>
```

### Tabelle

Le tabelle servono per tabulare colonne di dati. Una tabella si crea con il tag **\<table>**. **\<tr>** e **\<td>** indicano, rispettivamente, le righe e le colonne. Intere tabelle possono poi essere a loro volta contenute in celle di altre tabelle, che vengono quindi nidificate come scatole cinesi.

#### Regole

-   Non ci possono essere righe senza celle al suo interno.
-   Le colonne non si definiscono in modo esplicito ma si definiscono le celle all’interno delle righe tramite gli elementi **td**.
-   Si possono definire celle che occupano più di una colonna (**colspan**) o più di una riga (**rowspan**).
-   È possibile creare delle intestazioni per le colonne (o per le righe) con gli elementi th al posto di **td**.
-   Il tag **caption**, posto subito dopo il tag **table**, permette di inserire un titolo (in genere visualizzato sopra la tabella).
-   L’attributo **summary** permette di descrivere il contenuto della tabella

#### Raggruppare le righe

È possibile raggruppare alcune righe suddividendo la tabella in **header**, **body** e **footer**.

```html
<table>
    <thead>
        <tr>....</tr> <tr>....</tr> <tr>....</tr>
    </thead>
    <tfoot>
	    <tr>....</tr> <tr>....</tr> <tr>....</tr>
    </tfoot>
    <tbody>
	    <tr>....</tr> <tr>....</tr> <tr>....</tr>
    </tbody>
</table>
```

### Form

```html
<form action=“http://server/path/file.cgi" method=“post|get" >
	<!– elementi del form -->
</form>
```

Metodo **get**: è il predefinito. Viene utilizzato per leggere dati. Il browser allega la stringa di query all’url del programma CGI

-   http://server/path/file.cgi?parametro=valore
-   limite alla lunghezza della stringa
-   vulnerabilità dell’accesso

Metodo **post**: viene utilizzato per inviare dati. La stringa di query viene passata come input standard

-   maggiore facilità di gestione

#### Formato della stringa di query

-   Contiene i dati inviati cliccando il pulsante **Submit**
-   Il nome e il valore di ciascun elemento della form sono codificati come assegnamenti
-   Con il metodo **get** la pagina di destinazione può essere salvata come bookmark in modo da poter ripetere la query senza reinserire i dati
-   Se si usa il metodo **get** la stringa viene inserita dal server in una variabile d’ambiente
-   Se si usa il metodo **post** si deve leggere la stringa di query dall’input standard

#### Fieldset e Label

-   **fieldset**: permette di raggruppare elementi logicamente correlati
-   **legend**: permette di inserire una intestazione
-   **label**: associa un’etichetta ad un campo del form (non necessariamente adiacente) con **id** il valore dell’attributo **for**

#### Input

##### Attributi

-   **name**: serve per identificare l’input inviato al server.
-   **readonly=“readonly”**: i campi con questo attributo non sono
    editabili dall’utente.
-   **disabled=“disabled”**: i campi con questo attributo non sono
    editabili dall’utente.

##### Type

Questo tag permette da solo di creare diversi elementi di una form a seconda del contenuto dell’attributo type:

-   **text**: una singola riga di testo con maxlength elementi
-   **password**: una riga di testo offuscata
-   **checkbox**: un semplice on/off
-   **radio**: per selezionare una o più opzioni
-   **submit**: pulsante per inviare i dati del modulo
-   **reset**: pulsante per riportare i valori predefiniti nei campi del modulo
-   **hidden**: per dati non visibili o non editabili
-   **file**: per caricare file
-   **button**: per richiamare script lato client
-   **image**

#### Textarea

Permette all’utente di inserire testo più lungo di una riga.

```html
<textarea rows="20" cols="40" name="message">
	scrivi qualcosa qui
</textarea>
```

Gli attributi **rows** e **cols** sono obbligatori

#### Select

Permette di creare elenco di dati, in genere visualizzato come menù a tendina, su cui effettuare una o più scelte.

### Cosa non usare

Sono tag che si occupano di aspetti di presentazione o tag non validi:

-   b, i, big, small, marquee, blink, u, tt, sub, sup, center, hr
-   applet e embed (si deve usare object), font, frame, frameset, iframe

