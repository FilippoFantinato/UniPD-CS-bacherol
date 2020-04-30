#include <iostream>

#define SIZE 10

/*
	Realizzare una versione ricorsiva della funzione InsertionSort.
*/

// Side effect

int moveElementsSE(int *a, int i, int key)
{
	if(i < 0 || a[i] < key) return i;

	a[i + 1] = a[i];

	return moveElementsSE(a, --i, key);
}

void insertionSortRecSE(int *a, int index, int size)
{
	if(index == size) return;

	int key = a[index];

	int i = moveElementsSE(a, index - 1, key);

	a[i + 1] = key;

	insertionSortRecSE(a, index + 1, size);
}

void insertionSortNonRec(int *a, int size)
{
	int i, key;

	for(int j = 1; j < size; j++)
	{
		key = a[j];

		i = j - 1;

		while(i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}

		a[i + 1] = key;
	}
}

int main()
{
	int a[10] = { 800, 5, 8, 1, 6, 7, 8, 6, 4, 10 };

	insertionSortRecSE(a, 1, SIZE);

	for(int i = 0; i < SIZE; i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}
