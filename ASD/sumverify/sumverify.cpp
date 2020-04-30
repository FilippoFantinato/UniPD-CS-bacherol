#include <iostream>
#define SIZE 10

/*
	Realizzare una funzione Sum(A,key) che dato un array A e un intero key verifica se questo è esprimibile come la somma di due elementi di A ovvero se vi sono indici i e j tali che key = A[i] + A[j].
*/

bool sumVerify(int *a, int key)
{
	bool found = false;											// c0

	for(int i = 0; i < SIZE && !found; ++i) 					// n
	{
		for(int j = i + 1; j < SIZE && !found; ++j)				
		{
			found = key == (a[i] + a[j]);
		}
	}

	return found;
}

int main(int argc, char const *argv[])
{
	const int KEY = 0;

	int a[SIZE] = { 5, 5, 10, 15, 25, 1, 1, 1, 8, 9 };

	std::cout << (sumVerify(a, KEY) ? "TRUE" : "FALSE") << std::endl;

	return 0;
}