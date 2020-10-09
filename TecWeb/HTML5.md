# HTML5

## Sintassi

```html
<!DOCTYPE html>
<html lang="it">
    <head>
        <title></title>
        <meta charset="utf-8"></head>
    	<link rel="stylesheet" href="style.css" />
    	<script src="script.js"></script>
    </head>
    <body>

    </body>
</html>
```

## Tag

### Meta

-   Non deve necessariamente essere chiuso

#### Http-equiv

-   X-UA-compatible

#### Name

-   **viewport**:  può contenere nel content anche **initial-**
    **scale**, **minimum-scale**, **maximum-scale** e **user-scalable**

### Markup Strutturale

-   **section**: per raggruppare contenuti sullo stesso tema o logicamente collegati (ex. capitoli di un libro)
-   **article**: porzione di testo autocontenuto e indipendente dal resto del documento che possa essere distribuito in modo autonomo (ex. post di un blog, articolo di giornale)
-   **header**, **footer**: intestazione e piè pagina di una documento. **footer** identifica le informazioni su chi ha scritto i contenuti
-   **nav**: contiene elementi di supporto alla navigazione. Può comparire anche dentro un header
-   **aside**: sidebar, contenuto a parte, a supporto, non necessariamente a destra o a sinistra. Identifica un parte di contenuto che può essere rimossa senza diminuire il significato della pagina (o della sezione), ma che è legata al contenuto del tag in cui è annidata

#### Regole

-   Non ricorrere a section od article per soli motivi di stile o di scripting, in tal caso div è preferibile
-   **article**, **nav**, **section** e **aside** sono sectioning element, ovvero
    possono contenere **header**, **nav** e **footer**

### Altri tag semantici

-   **figure**
-   **mark**
-   **time**: (con l’attributo datetime che contiene la data - o
    l’ora - in formato XML)
-   **meter**: per indicare una misura in una scala che ha un
    minimo (max) ed un massimo (min)
-   **progress**: per indicare un valore che sta cambiando
-   **small**: per indicare le note a piè pagina, i termini in
    piccolo dei contratti, etc

### Form

#### Attributi aggiuntivi

-   **target**: indica dove visualizzare la risposta (_blank, _self,_parent, _top, _iframename)
-   **autocomplete**
-   **novalidate**

#### \<input />

Vengono aggiunti i seguenti valori per l'attributo **type**:

-   **number** (inserisce due freccette per aumentare o
    diminuire il valore, ma rimane editabile), **range**
-   **color**
-   **email**, **url**, **tel**
-   **search**
-   **datetime**, **datetime-local**, **date**, **month**, **time**, **week**

#### Tag aggiuntivi

-   **datalist**: per definire liste di suggerimenti
-   **keygen**: per generare le chiavi per un sistema crittografico
-   **menu**: per i menù contestuali
-   **output**: che funge da segnaposto per i risultati di un
    calcolo

#### Nuovi attributi per i controlli

- **required**
- **formnovalidate**
- **pattern**: contiene un’espressione regolare per la validazione dell’input
- **placeholder**: contiene un suggerimento
- **autocomplete**, **autofocus**
- **spellcheck**
- **min**, **max**, **step**
- **multiple**

### Innovazioni per le liste ordinate

Aggiunge al tag **\<ol>** i seguenti attributi

-   **reversed**
-   **start**: indica il numero con cui parte la lista
-   **type**: specifica il tipo di marcatore

Inoltre aggiunge al tag **\<li>** l’attributo **value** che consente di
impostare un numero arbitrario

#### \<figure>\</figure> e \<figcaption>\</figcaption>

Permettono di definire figure e didascalie

```html
<figure>
    <img src="figure.jpg">
    <figcaption>Didascalia della figura</figcaption>
</figure>
```

Un’immagine non ha bisogno dell’attributo **alt** se ha associata una didascalia