# QT

Qt è completamente ad oggetti ed event driven

Qt estende C++ con segnali e slot utilizzando il MOC (Meta Object Compiler)

Molte funzionalità non GUI:

* Accesso a database SQL
* Qcontainers
* Javascript
* XML e JSON support
* Threads
* Network programming
* Gestione di file cross-platform

## Event Driven Programming

![Screenshot from 2020-05-18 21-50-06](/home/filippofantinato/Pictures/Screenshot from 2020-05-18 21-50-06.png)

* In qt tutte le classi ereditano da QObject

* QObject ha varie caratteristiche interessanti
  * Relazioni di parent/siblings (con gestione automatica della distribuzione parentale)
  * Signals/Slots

## Object Trees & Ownership

QWidget eredita da QObject. In QT tutte le classi GUI ereditano da QWidget. Ogni elemento visibile di GUI è una QWidget.

## Segnali e Slots

Ogni oggetto può emettere e ricevere segnali o slot.

![Screenshot from 2020-05-18 22-50-01](/home/filippofantinato/Pictures/Screenshot from 2020-05-18 22-50-01.png)

**Segnali:** Funzioni che vengono solamente dichiarate e vengono emesse al verificarsi di qualche evento

**Slots:** Funzioni dotate di un'implementazione

Per connettere oggetti che emettono i segnali con gli oggetti che emettono uno slot, esiste la funzione **connect**

* Ogni QObject definisce i segnali che può emettere
* Ogni oggetto può connettere i propri slots a diversi segnali (tipicamente di altri oggetti)
* Quando un QObject emettere un segnale **sig**, tutti gli slot connessi a **sig** vengono invocati
* Un segnale può invocare diversi slots
* Uno slot può essere connesso a diversi segnali

```c++
QMetaObject::Connectio QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection) [static]
```

Bisogna sempre usare le macro **SIGNAL()** e **SLOT()**, quando si specificano i segnali ed i metodi.

## Layout Manager

Gestore del layout di un contenitore di componenti widget, con varie politiche di piazzamento.

## Slots

* Gli slots sono metodi ordinari di una classe QT, ma preceduti dalla keyword **slots**.
* Una classe contenete propri slots deve includere nella parte privata la macro QObject::Q_OBJECT. Serve al MOC

## Signals

* Aggiungere sempre alla parte privata di una classe con segnali propri, la macro QObject::Q_OBJECT. Serve al MOC
* Un segnale si dichiara (e non si implementa) come un metodo ordinario preceduto dalla QT keyword **signals**
* Il segnale non va implementato
* Per emettere il segnale si usa la QT keyword **emit**