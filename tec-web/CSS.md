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

<center><bold>(num id, num attributi, num tag html)</bold></center>

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
- 