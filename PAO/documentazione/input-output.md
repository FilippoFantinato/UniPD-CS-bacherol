# Input Output

# ![](/home/filippofantinato/Pictures/Screenshot from 2020-03-12 19-22-02.png)

## Stream

E' l'astrazione di un dispositivo di I/O ed è una sequenza illimitata di celle ciascuna contente Byte

- La posizione delle celle di uno stream parte da 0

- Si utilizza il supporto di un buffer associato allo stream

* Uno stream può trovarsi nello stato di **end-of-file**

### Stati di uno stream

Sono presenti 8 stati di funzionamento diversi (2^3), rappresentato dal campo dati **state** della classe base ios che corrisponde al numero binario 

<center><strong>bad fail cof</strong></center>

dove bad, fail e eof sono dei bit (0 o1) di stato:

- eof == 1 <==> lo stream e' in posizione di end-of-file.
- fail == 1 <==> la precedente operazione sullo stream e' fallita. Si tratta di un errore senza perdita di dati, normalmente e' possibile continuare. 
- bad == 1 <==> la precedente operazione sullo stream e' fallita con perdita di dati. Si tratta di un errore fatale/fisico.

### IStream

Include l'overloading degli operatori di input per i tipi primitivi, un'array di byte e le stringhe.

Tutti gli operatori di input ignorano le spaziature presenti prima del valore da prelevare

Quando un operazione di input fallisce (fail == 1) non viene effettuato alcun prelievo dallo stream e la variabile argomento di operator>> non subisce modifiche

### OStream

### Ifstream, Ofstream, fstream

Open mode:

1. **in**
2. **out**
3. **app** (append)
4. **binary**
5. **nocreate**
6. **ate** (spostamento a EOF dopo l'apertura)
7. **trunc**

**Close** permette di chiudere lo stream

**tellg | tellp** ritorna la posizione di input | output nello stream

**seekg | seekp** setta la posizione di input | output nello stream

Esistono delle posizioni predefinite nella classe IOS: 

- **beg** 
- **cur**
- **end**

### Stream di stringhe (I/O su RAM)

Le classi utilizzabili sono istringstream, ostringstream e stringstream presenti nell'header <sstream>

Servono per eseguire il parsing su delle stringhe, gestendole come degli stream normali.