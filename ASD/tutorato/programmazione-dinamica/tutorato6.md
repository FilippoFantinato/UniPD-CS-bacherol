# Esercizio

Dare un algoritmo per individuare all'interno di una stringa a1...an una sottostringa palindroma

ii) Algoritmo
palindrome(A, n)
	for i = 1 to n
		L[i, i-1] = 0 // i>j: a
		L[i, i] = 1

	for len=2 to n
		j = i+len-1
		if(A[i]=A[j]) and (L[i+1, j-1]==j-i-1)
			L[i, j]=L[i+1, j-1]+2
		else
			L[i, j]=max(L[i, j-1], L[i+1, j])
	return L[1, n]

iii) Individuare sottostringa palindroma di lunghezza max.
P[i, j] = inizio sottostringa palindroma lunghezza massima in A[i, j]


palindrome(A, n)
	for i = 1 to n
		L[i, i-1] = 0 // i>j: a
		L[i, i] = 1
		P[i, i] = i

	for len=2 to n
		j = i+len-1
		if(A[i]=A[j]) and (L[i+1, j-1]==j-i-1)
			L[i, j]=L[i+1, j-1]+2
			P[i, j]=i
		else
			if(L[i,j-1]>=L[i+1,j])
				L[i,j]=L[i,j-1]
				P[i,j]=P[i,j-1]
			else
				L[i,j]=L[i+1,j]
				P[i,j]=P[i+1,j]

	start = P[1..n]
	end = start + L[1, n] - 1
	return A[start...end]

iv) Complessità
	T(n)=\Theta(n^2)

Esercizio 19
E=x1op1x2op2x3...xn
7+10*2

i) vij = min valore da x1 a xj
vij=xi se i=j
vij=min{} se j>i

E=(x1op1x2)op2(x3...xn)
