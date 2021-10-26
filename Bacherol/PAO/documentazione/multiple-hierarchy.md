# Multiple Hierarchy

## Diamante

La derivazione a diamante consiste nel caso quando due classi B e C ereditano dalla  stessa classe A

**Il problema consiste in ambiguita' nei campi e nelle funzioni e spreco di memoria durante il subtyping e nell'utilizzo del sotto oggetto.**

## Unique final overrider rule

## Costruttori

1. Prima di tutto vengono eseguiti, una sola volta, i costruttori delle classi base virtuali che si trovano nella gerarchia di derivazione di D. Dato che ci possono essere più basi virtuali nella gerarchia, la chiamata procede da sinistra verso destra e dall'alto verso il basso
2. Vengono richiamati i costruttori delle superclassi dirette non virtuali di D: Questi costruttori escludono di richiamare eventuali costruttori di classi virtuali già richiamati al passo 1.
3. Infine viene eseguito il proprio costruttore di D

Se non esplicite le chiamate presenti nelle fasi 1. e 2., vengono inserite automaticamente con quella di default.
