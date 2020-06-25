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

Cosa possiamo dire della matrice $$A^tA$$ del sistema delle equazioni normali?

È quadrata, $$A^tA\in\R^{n \times n}$$, simmetrica ($$(A^tA)^t=A^t(A^t)^t=A^tA$$) e semidefinita positiva.

Infatti $$\forall z\in \R^n$$
$$
(A^tAz, z)=(Az, Az)=||Az||^2_2 \ge 0
$$
Inoltre $$(z, A^tAz)=||Az||_2^2=0 \iff Az=0$$ (cioè se e solo se z è nel nucleo di A).

Se le colonne di A (ricordiamoci che A è rettangolare $$m \times n$$ con $$m>n$$) cono linearmente indipendenti, cioè se $$rango(A)=n$$, allora $$Az=0 \iff z=0$$, di conseguenza $$A^tA$$ è definita positiva e quindi non singolare.

In altre parole se A ha $$rando\_max=n$$ la soluzione ai minimi quadrati del sistema sovradeterminato è unica.

Nel caso particolare dei minimi quadrati polinomiali di grado k, abbiamo visto, adesso, che $$A=V$$ ha rango massimo se esistono almeno n=k+1 nodi di campionamento distinti tra gli $$m=N$$ nodi (e quindi di sicuro se gli N nodi sono tutti distinti come è naturale).

**SOLUZIONE DEL SISTEMA DELLE EQUAZIONI NORMALI**

Abbiamo appena dimostrato che se $$rango(A)=n$$ la soluzione di $$Ax=b$$ ai minimi quadrati è l'unica soluzione del sistema non singolare $$A^tAx=A^tb$$.

Quindi si potrebbe pensare di risolvere il sistema sovradeterminato applicando as esempio il MEG al sistema delle equazioni normali.

Per fare questo però bisogna calcolare ed utilizzare $$A^tA$$, che non è la strada migliore perchè $$A^tA$$ tende ad essere mal condizionata e nelle applicazioni è naturale che ad esempio il vettore b (e quindi anche $$A^tb$$) sia affetto da errori.

Perchè $$A^tA$$ tende ad essere mal condizionata? Osserviamo che 
$$
K_2(A^tA)=||A^tA||_2 ||(A^tA)^{-1}||_2 = \frac{max\lambda_i(A^tA)}{min\lambda_i(A^tA)}
$$
essendo $$A^tA$$ simmetrica e definita positiva ed è questo rapporto di autovalori che tende ad essere grande, perchè
$$
k_2(A^tA)=(K_2(A))^2>>k_2(A)>1
$$
Qui però stiamo usando il concetto di condizionamento di una matrice rettangolare, che non abbiamo discusso in questo corso perchè ha bisogno di una generalizzazione del concetto di autovalore (a quelli che sono detti i "valori singolari" di una matrice, che coincidono con i moduli degli autovalori nel caso quadrato).

Per "intuire" cosa succede però consideriamo il caso di $$A$$ quadrata e simmetrica: allora $$A^tA=A^2$$ e $$\lambda_i(A^tA)=\lambda_i(A^2)=(\lambda_i(A))^2$$ sono gli autovalori di $$A^tA$$, quindi essendo anche $$A^2$$ simmetrica 
$$
k_2(A^tA)=k_2(A^2)=\frac{max\lambda_i(A^2)}{min\lambda_i(A^2)}=(\frac{max|\lambda_i(A^2)|}{min|\lambda_i(A^2)|})^2=(k_2(A))^2>>k_2(A)
$$
perchè come sappiamo $$k(a) \ge 1$$ in qualsiasi norma matriciale indotta e $$k_2(A)>1$$ se $$A$$ (simmetrica) ha almeno 2 autovalori distinti.

Esiste però una strada alternativa per la soluzione di $$A^tAx=A^tb$$, che ?entra? di usare direttamente la matrice mal condizionata $$A^tA$$ ed è basata su una delle più importanti fattorizzazioni di matrice, la fattorizzazione QR, che permette di scrivere una qualsiasi matrice $$A \in \R^{m \times n}$$ con $$m \ge n$$ e $$rango(n)$$ come prodotto di una matrice TRIANGOLARE SUPERIORE (non singolare).

**TEOREMA** (fattorizzazione QR di una matrice rettangolare)

Sia $$A \in \R^{m \times n}, m \ge n : rango(A)=n$$, allora $$\exists Q \in \R^{m \times n}$$ ortogonale (cioè $$Q^tQ=1$$) e $$\exists R \in \R^{n \times n}$$ triangolare superiore con $$det(R) \ne 0$$ tale che
$$
A=
\begin{pmatrix}
a_{11} & ... & a_{1n} \\
a_{21} & ... & a_{2n} \\
. & ... & . \\
. & ... & . \\
. & ... & . \\
a_{m1} & ... & a_{mn} \\
\end{pmatrix}
= QR =
\begin{pmatrix}
q_{11} & ... & q_{1n} \\
q_{21} & ... & q_{2n} \\
. & ... & . \\
. & ... & . \\
. & ... & . \\
q_{m1} & ... & q_{mn} \\
\end{pmatrix}
\begin{pmatrix}
r_{11} & ... & r_{1n} \\
. & ... & . \\
r_{n1} & ... & r_{nn} \\
\end{pmatrix}
$$
Cerchiamo ora di capire il significato di questo risultato e di intuirne la dimostrazione (che non faremo rigorosamente).

Innanzitutto, cosa significa che $$Q$$ è ortogonale, cioè che $$Q^tQ=1$$?

Osserviamo che $$Q^t \in \R^{n \times m}$$ ha per righe le colonne di Q, quindi $$Q^tQ = I \in \R^{n \times n}$$ cioè
$$
R_i(Q^t)l_j(Q)=(l_i(Q), l_i(!))=\delta_{ij}\\
prodotto\space riga\space i,colj = prodotto \space scalare = delta\space di\space kronecker
$$
ovvero le colonne di Q sono vettori ORTONORMALI di $$R^m$$.

Siccome $$R$$ è invertibile
$$
QRR^{-1}=Q=AR^{-1}
$$
Ora, si può dimostrare che l'inversa di una matrice triangolare è triangolare dello stesso tipo (accettiamo questo risultato).

Quindi
$$
R^{-1}=
\begin{pmatrix}
\delta_{11} & \delta_{12} & ... & \delta_{1n} \\
& \delta_{22} & ... & \delta_{2n} \\ 
\bigcirc & & ... & \delta_{nn} \\ 
\end{pmatrix}
$$
con $$\delta_{ii} \ne 0, \forall i$$.

Consideriamo le colonne di $$Q=AR^{-1}$$

Per la solita interpretazione del prodotto matrice-vettore, in questo caso il prodotto di $$A$$ per le colonne di $$R^{-1}$$, 
$$
l_1(AR^{-1})=l_1(Q)=\delta_{11} l_1(A) \\
l_2(AR^{-1})=l_2(Q)=\delta_{12} l_1(A) + \delta_{22} l_2(A)\\
l_3(AR^{-1})=l_3(Q)=\delta_{13} l_1(A) + \delta_{23} l_2(A) + \delta_{33} l_3(A) \\
...\\
l_j(AR^{-1})=l_j(Q)=\sum_{i=1}^j\delta_{ij}l_i(A), i \le j \le n
$$
cioè la colonna j-esima di $$AR^{-1}=Q$$ si ottiene come combinazione lineare delle prime j colonne di $$A$$ ed essendo $$Q$$ ortogonale questa combinazione lineare ha l'effetto di ortonormalizzare le colonne.

Ma sappiamo dall'algebra lineare che c'è una algoritmo che fa esattamente questo, il procedimento di ortonormalizzazione di Gauss-Schmidt, che costruisce un set di vettori ortogonali a partire da un set di vettori linearmente indipendenti.

Ovvero dietro la possibilità di fattorizzazione come prodotto QR una matrice $$m \times n$$ con $$m \ge n$$ e colonne linearmente indipendenti (cioè $$rango(A)=n$$) c'è il procedimento di Gauss-Schmidt.

In pratica questo algoritmo non è stabile in aritmetica floating-point al crescere del numero di vettori, ma ci dice che la fattorizzazione è possibile (e ci sono algoritmi stabili per realizzarla di cui però non discuteremo, come il metodo delle "trasformazioni di HouseHolder").

Quello che ci interessa è far vedere come si può usare in modo molto semplice la fattorizzazione QR per risolvere il sistema delle equazioni normali per i minimi quadrati.

Sia $$A \in \R^{m \times n}, m \ge n, rango(A)=n$$, fattorizzando $$A=QR$$, si ha che 
$$
A^tA = (QR)^tQR = R^tQ^tQR = R^tIR = R^tR, A^tb = R^tQ^tb
$$
quindi il sistema $$A^tAx=A^tb$$ diventa
$$
R^tRx=R^tQ^tb
$$
ma essendo $$R$$ (e quindi $$R^t$$) invertibile
$$
(R^t)^{-1}R^tRx = Rx = (R^t)^{-1}R^tQ^tb = Q^tb
$$
Cioe il sistema $$A^tAx=A^tb$$ equivale al sistema triangolare superiore
$$
Rx = d = Q^tb
$$
che si può facilmente risolvere con la sostituzione all'indietro.

In realtà non c'è un vantaggio sostanziale dal punto di vista del costo computazionale rispetto al calcolo di $$A^tA$$ e all'applicazione del MEG/LU (che in questo caso di una matrice simmetrica definita positiva ha una forma semplificata che non discuteremo derra "fattorizzazione di Cholesky").

Invece c'è un grosso vantaggio dal punto di vista della stabilità perchè si può dimostrare che 
$$
k_2(A^tA) = (k_2(A))^2 >> k_2(R)
$$
In pratica andremo sempre a risolvere un sistema perturbato
$$
\overline{R}\overline{x} = \overline{d}
$$
dove però $$R$$ è condizionata molto meglio di $$A^tA$$.

Si può infatti dimostrare (non lo faremo per i motivi detti sopra parlando di $$k_2(A^tA)$$).

Per intuirlo, consideriamo di nuovo il caso di $$A$$ quadrata ($$m=n$$) e simmetrica: allora da $$A=QR$$ abbiamo che
$$
||R||_2 = ||Q^tA||_2 \le ||Q^t||_2||A||_2=||A||_2
$$
Perchè $$Q^t$$ è ortogonale e 
$$
||Q^t||_2 = \sqrt{max|\lambda_i(QQ^t)|}=\sqrt{max|\lambda_i(I)|}=1
$$
e allo stesso modo ($$Q^{-1} = Q^t$$)
$$
||R^{-1}||_2 = ||(Q^tA)^{-1}||_2 = ||A^{-1}Q||_2 \le ||A^{-1}||_2 ||Q||_2 = ||A^{-1}||_2
$$
quindi $$k_2(R) \le k_2(A)$$ (in realtà si può dimostrare che $$k_2(R) = k_2(A)$$)