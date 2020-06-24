# Lezione 24

### Sistemi lineari sovradeterminati, minimi quadrati, sistema delle equazioni normali, fattorizzazione QR

In questa lezione ci occuperemo della soluzione numerica di sistemi lineari SOVRADETERMINATI, cioè sistemi
$$
Ax=b, A\in \R^{mxn}, b\in\R^{m}, x\in\R^{n}
$$
con m > n (ci sono più equazioni che incognite), in forma estesa
$$
\begin{pmatrix}
a_{11} &...& a_{1n} \\
a_{21} &...& a_{2n} \\
. & . & .\\
. & . & .\\
. & . & .\\
. & . & .\\
a_{m1} &...& a_{mn} \\
\end{pmatrix}
\begin{pmatrix}
x_1\\
x_2\\
.\\
.\\
.\\
x_n\\
\end{pmatrix}
= 
\begin{pmatrix}
b_1\\
b_2\\
.\\
.\\
.\\
b_m\\
\end{pmatrix}
$$
In generale un sistema sovradeterminato non ha soluzione in senso classico, cioè non è detto che $$\exists x\in\R^n : Ax=b$$.

Infatti, ricordando la solita proprietà, cioè che un prodotto matrice-vettore si può interpretare come combinazione lineare delle colonne della matrice con coefficienti gli elementi del vettore
$$
Ax=x_1l_1(A) + ... + x_nl_n(A)
$$
un sistema (sovradeterminato) ha soluzione se e solo se 
$$
b\in<l_1(A),...,l_n(A)>\subset\R^m
$$
cioè se e solo se b sta nel sottospazio di $$\R^m$$ generato dalle colonne di A (si tratta di un sottospazio effettivo perchè ha dimensione $$\le n < m$$)

Visto che una soluzione $$x\in \R^n : Ax=b$$ non esiste in generale, cioè non esiste $$x\in \R^n : dist_2(b, Ax)=||b-Ax||_2 = 0$$, possiamo cercare x in modo da minimizzare tale distanza, ovvero risolvere il problema di minimo in $$\R^n min_{x\in \R^n}||b-Ax||_2$$ oppure visto che è equivalente
$$
min_{x\in \R^n}\Phi(x), \Phi(x) = ||b-Ax||_2^2, x\in \R^n
$$
dove
$$
\Phi(x) = \sum_{i=1}^{m}(b-Ax)_i^2 = \sum_{i=1}^m (b_i-(Ax)_i)^2 = \sum_{i=1}^m(b_i-(\sum_{j=1}^n(a_{ij}x_j)))^2
$$
Le ultime due operazioni sono la somma degli scarti quadratici.

Si vede facilmente che $$\Phi(x)$$ è un polinomio di grado 2 nelle n variabili $$x_1, x_2, ..., x_n$$

In effetti abbiamo già incontrato una situazione di questo tipo con l'approssimazione polinomiale ai minimi quadrati nella lezione 15, dove si cercava un polinomio di grado k (cambiando leggermente la notazione per non fare confusione coi simboli attuali) che rendesse minima la somma degli scarti quadratici rispetto ai valori $$y_1, ..., y_N$$ di una funzione campionata su N ascisse $$t_1, ..., t_N$$, ovvero si cercavano dei coefficienti $$c_1, ..., C_{k+1}$$ che realizzassero 
$$
min_{c\in\R^{k+1}} \Phi(c), \Phi(c) = \sum_{i=1}^N(y_i-(Vc)_i)^2 = ||y-Vc||_2^2
$$
dove $$V=(t_i^j)\in \R^{Nx(k+1)}$$, è una matrice di Vandermonde rettangolare ($$N>k+1$$ e tipicamente $$N >> K+1$$)

In effetti, visto che l'uguaglianza $$Vc=y$$, cioè $$||y-Vc||_2 = 0$$ non può essere ottenuta in generale perchè il sistema è sottodeterminato, si va a minimizzare $$||y-Vc||_2^2$$

È lo stesso tipo di problema che stiamo affrontando adesso in forma generale, la soluzione ai MINIMI QUADRATI di un sistema sovradeterminato (nel caso polinomiale rientriamo nella formulazione generale con $$A=V, b=y, x=c, m=N, n=k+1$$)

Ovvero, il problema polinomiale dei minimi quadrati si può rivedere come particolare istanza della soluzione ai minimi quadrati di un sistema sovradeterminato

**TEOREMA** (sistema delle equazioni "normali" per la soluzione ai minimi quadrati di un sistema lineare sovradeterminato)

Il vettore $$x\in\R^n$$ minimizza $$\Phi(x)=||b-Ax||_2^2$$

$$\iff$$

risolve il sistema lineare $$n \times n$$ $$A^tAx = A^tb$$ (sistema delle equazioni normali) 

**Dimostrazione**

Siccome la dimostrazione è del tutto analogo a quella già fatta nel caso dei minimi quadrati polinomiali, la sviluppiamo senza ridiscutere tutti i dettagli.

Per prima cosa $$\Phi(x)$$ è minimo se e solo se $$\Phi(x+z)\ge\Phi(x)\forall z\in \R^n$$

Ora 
$$
\Phi(x+z)=||b-A(x+z)||^2_2=\\
=(b-A(x+z), b-A(x+z))=\\
=(b-Ax-Az, b-Ax-Az)=\\
=(b-Ax, b-Ax) - 2(Az, b-Ax) + (Az, Az)=\\
=\Phi(x)+2(z, A^t(Ax-b))+||Az||^2_2
$$
$$(\Leftarrow)$$

Se $$A^tAx=A^tb$$ allora $$\Phi(x+z)=\Phi(x)+||Az||_2^2\ge\Phi(x)\forall z, ||Az||^2_2\ge0$$ cioè $$\Phi(x)$$ è minimo

$$(\Rightarrow)$$

Se $$\Phi(x)$$ è minimo allora $$\forall \varepsilon > 0$$ e $$\forall v \in\R^n, ||v||_2 = 1$$ 

$$\Phi(x+\varepsilon v)=\Phi(x)+2(\varepsilon v, A^t(Ax-b))+||\varepsilon v||_2^2\ge\Phi(x)$$

cioè
$$
2\varepsilon(v, A^t(Ax-b))+\varepsilon^2\ge0
$$
e dividendo per $$\varepsilon$$
$$
2(v, A^t(Ax-b))+\varepsilon \ge 0, \forall \varepsilon \ge 0, \forall \varepsilon, v
$$
da cui per $$\varepsilon \rightarrow 0$$
$$
(v, A^t(Ax-b)) \ge 0, \forall v
$$
Ma allora prendendo $$-v$$
$$
(-v, A^t(Ax-b)) \ge 0, \forall v\\
(v, A^t(Ax-b)) \le 0, \forall v
$$
e quindi
$$
(v, A^t(Ax-b))=0, \forall v
$$


da cui $$A^t(Ax-b) = 0$$, perchè l'unico vettore ortogonale a tutti i versori è il vettore nullo, cioè $$A^tAx = A^tb$$

