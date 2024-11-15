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

#### Input

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

#### Figure e Figurecaption

Permettono di definire figure e didascalie

```html
<figure>
    <img src="figure.jpg">
    <figcaption>Didascalia della figura</figcaption>
</figure>
```

Un’immagine non ha bisogno dell’attributo **alt** se ha associata una didascalia.

Permette anche di specificare se qualche parola è scritta in un'altra lingua.

### Audio

Permette la riproduzione di file audio in modo nativo

```html
<audio src=“song.mp3” autoplay loop controls />

<audio controls="controls">
	<source src="song.ogg" type="audio/ogg" />
	<source src="song.mp3" type="audio/mp3" />
	<p>Testo sostitutivo dell’audio.</p>
</audio>
```

### Video

Funziona esattamente come **audio**

Da **javascript** si può selezionare il formato del file specifico, da **HTML** il tipo.

```html
<video width="320" height="240" controls="controls" poster="img.jpg">
    <source src="movie.mp4" type="video/mp4" />
    <source src="movie.ogg" type="video/ogg" />
    <p>Testo alternativo al video.</p>
</video>
```

## Lavorare in locale

### Web Storage

Web Storage offre due oggetti che memorizzano i dati sotto forma di coppie <nome, valore>:

-   **sessionStorage**: mantiene i dati solo fino alla chiusura del browser
-   **localStorage**: mantiene i dati fino allo svuotamento della cache

### Web SQL Database

Database relazionale

### IndexedDB

Si basa su una memorizzazione basata su oggetti indicizzati molto veloce ed efficiente

## Cache manifest

Aiuta lo sviluppo che possono lavorare offline, ovvero senza un costante collegamento alla rete.

Il file **.manifest**, chiamato anche **cache manifest**, elenca le risorse disponibili anche in assenza di connessione alla rete.

La prima riga deve contenere la stringa **CACHE MANIFEST**

Il file è organizzato in sezioni: 

-   **CACHE**: pagine da salvare in cache
-   **NETWORK**: pagine che necessitano la rete
-   **FALLBACK**: pagine che necessitano della rete, con la corrispettiva pagina da restituire se non c'è connessione

```html
CACHE MANIFEST

# versione 0.1

CACHE:
Risorsa1.html
Risorsa2.html

NETWORK:
Aggiorna.cgi

FALLBACK:
Online.html Offline.html
/news/* avviso.html
```

```html
<!DOCTYPE html>
<html manifest=“risorsa.manifest”>
    
</html>
```

-   Il **file che contiene** il riferimento al file .manifest viene
    comunque conservato in locale anche se non presente
    nel file .manifest
-   Il file **.manifest** deve essere servito con il tipo **MIME**
    corretto, ovvero **text/cache-manifest**