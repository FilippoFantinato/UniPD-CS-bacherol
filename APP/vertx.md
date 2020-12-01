# Vertx

Per prima cosa dobbiamo pianificare l'API che ilservizio esporrà. 

Per rendere l'esempio più concreto, esporremo sia una API Web usabile da browser, sia una JSON usabile da un client automatico.

## API Design

Creare una API è un'arte: fatta di stili, di scuole, di preferenze, di gusti personali e richiede esperienza.

L'interfaccia del nostro codice è il modo in cui comunichiamo agli altri sviluppatori cosa il nostro codice fa e come va usato.

## Home page

**GET /**

**HTML**: Pagina HTML di benvenuto

## Ingresso al gioco

**POST /game**

**HTML**: redirect al form di gioco

**JSON**: url dove ottenere lo stato del gioco

## Mossa in un gioco

**POST /game/{id}** move=x

**HTML**: form con lo stato di gioco

**JSON**: stato del gioco