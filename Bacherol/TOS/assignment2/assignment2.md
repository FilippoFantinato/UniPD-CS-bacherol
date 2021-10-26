# Assignment 2

## Interfaccia e oggetti

- Interfaccia **TakeAwayBill**
- Classe **MenuItem**:
    - **itemType**: enumerazione che rappresenta i tipi di elementi presenti nel menu (Gelati, Budini e Bevande)
    - **name**
    - **price**
- Classe **User**: contiene l’identificativo e i dati anagrafici del utente reigistrato

## Svolgimento

- Predisposizione del repository github
- Definizione delle attività nel Issue Traking System
- Creazione del progetto utilizzando l’archetipo maven quick start
- Configurazione del processo di build
- attivazione e configurazione dell’analisi statica
- Predisposizione della Continuous Integration con travisCI o GitHub Actions
- Sviluppo del codice sorgente e dei test

## Issue Tracking System

- registrare la nuova versione
- creare la project board
- creare le attività per la realizzazione del assigment 2

## Version Control System

Le attività possono essere gestite utilizzando il work flow Feature Branch.

## Project Automation

- Creare il progetto con Maven utilizzando l’archetipo: maven-archetype-quickstart
- Utilizzare i seguenti parametri:
    - **groupId**: it.unipd.tos
    - **artifactId**: icecream-shop-manager

Configurare il Build Lifecycle in modo da:

- Eseguire la compilazione del progetto (fase compile)
- Eseguire i test di unità (fase test)
- Eseguire l’analisi statica del codice con checkstyle nella fase package (Vedi laboratorio Maven: Plugin - Universal reuse of business logic).

## Test di Unità

- Sviluppare i test di unità per arrivare ad una copertura del code del 100% dei sorgenti di produzione
- I test di unità devono essere sviluppati con il framework JUnit 4.12 o 5 e seguire le convenzioni Maven (vedi qui e qui)
- Le firme dei metodi di test devono essere parlanti. Vedi il formalismo riportato nel laboratorio JUnit.
- Creare dei test di unità per soddisfare le caratteriste A-TRIP e Right Bicep viste a lezione. È richiesta la copertura del codice >= 85%.
- [Opzionale] sviluppare il progetto utilizzando l’approccio TDD

## Analisi statica del codice

Configurare il plugin maven checkstyle in modo da effettuare le seguenti verifiche al codice di produzione (creare il file checkstyle.xml e configurare i seguenti moduli):

- [BooleanExpressionComplexity](https://checkstyle.sourceforge.io/config_metrics.html#BooleanExpressionComplexity)
- 