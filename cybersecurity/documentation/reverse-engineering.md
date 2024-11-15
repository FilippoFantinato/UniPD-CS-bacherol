# Reverse Engineering

## Linux process memory

![](/home/filippofantinato/Desktop/UniPD/cybersecurity/documentation/reverse-engineering/linux-memory-process.png)

## Flags

Tutte le istruzioni possono modificare un registro speciale chiamato **flags**, che può assumere i seguenti valori:

* **ZF**: Zero flag
* **SF**: Sign flag
* **AF**
* **PF**
* **OF**
* **CF**

## Istruzioni

### Mov

```assembly
MOV <dst>, <src>
```

* Copia **src** in **dst**

### Lea

```assembly
LEA <dst>, <src>
```

* Carica l'indirizzo di **src** dentro **dst**
* È utilizzato per accedere agli elementi di buffer/array
* Usato per eseguire semplici operazioni matematiche

### Push

```assembly
PUSH <src>
```

* Decrementa **RSP** e mette **src** nello stack

### Pop

```assembly
POP <dst>
```

* **dst** prende il valore nel top dello stack e **RSP** viene incrementato

### Add

```assembly
ADD <dst>, <src>
```

* **dst** += **src**

### Sub

```assembly
SUB <dst>, <src>
```

* **dst** -= **src**

### Compare

```assembly
CMP <dst>, <src>
```

* Compara **dst** e **src**, aggiornando **ZF**

### Jump incondizionato

```assembly
JMP <dst>
```

* Salta all'indirizzo specificato in **dst**

### Jump condizionato

```assembly
JZ JE => jump if ZF = 1
JNZ JNE => jump if ZF = 0
JB JA => Jump if <dst> Below/Above <src> (unsigned)
JL JG => Jump if <dst> Less/Greater than <src> (signed)
```

### XOR

```assembly
XOR <dst>, <src>
```

### NOP

```assembly
NOP
```

* Non fa nulla, utile al patching (rimuovere CALL, CMP, ...)

## Chiamata a funzione

### Call

```assembly
CALL <dst>
```

* Chiama la subroutine all'indirizzo **dst**

### Ret

```assembly
RET
```

* Ritorna dalla subroutine
* Valori ritornati spesso in **RAX**/**EAX**

## Patching

Si cambia il programma, dopo aver capito cosa fa

### Strategia con hex editor

1. Copia del binario
2. Usare un disassembler per trovare le istruzioni da patchare
3. Trovare il binario delle istruzioni hex
4. Modifica e salva
