#include <iostream>

#define SIZE 10

/*
	Realizzare una funzione Dup(A,p,r) che verifica, in modo divide et impera, la presenza di duplicati nell'array A, restituendo un booleano. Estenderla ad una funzione DupCount(A,p,r) che conti il numero di duplicati, ovvero il numero di coppie {(i,j)∣i≠j ∧ A[i]=A[j]}. 
	(Può essere interessante anche considerare varianti in cui si contano i valori ripetuti ovvero {A[i]∣∃j. j≠i.A[i]=A[j]} o gli indici corrispondenti a ripetizioni ovvero {i∣∃j. j≠i.A[i]=A[j]}.)
*/

bool isEqual(int first, int second) { return first == second; }

int dupCount(int *a, int p, int r, int count = 0)
{
	if(p < r)
	{
		if(isEqual(a[p], a[r]))
		{
			++count;
		}

		count = dupCount(a, p, r - 1, count);
	}
	else
	{
		if(p != SIZE)
		{
			count = dupCount(a, p + 1, SIZE - 1, count);
		}
	}

	return count;
}

bool dup(int *a, int p, int r)
{
	bool foundDup = false;
	
	if(p < r)
	{
		foundDup = isEqual(a[p], a[r]);

		if(!foundDup)
		{
			foundDup = dup(a, p, r - 1);
		}
	}
	else
	{
		if(p != SIZE)
		{
			foundDup = dup(a, p + 1, SIZE - 1);
		}
	}

	return foundDup;
}

int main(int argc, char const *argv[])
{
	int wD[SIZE] = { 8, 2, -1, 8, 3, -1, 5, 6, 7, 1 };
	int wOD[SIZE] = { 8, 1, 2, 4, 5, 3, 6, 7, 10, 9 };

	bool thereAreDuplicate = dup(wD, 0, SIZE - 1);

	int duplicates = dupCount(wD, 0, SIZE - 1);

	std::cout << (thereAreDuplicate ? "TRUE" : "FALSE") << std::endl;
	std::cout << "Duplicates number: " << duplicates << std::endl;

	return 0;
}
