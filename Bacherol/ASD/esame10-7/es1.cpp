#include <vector>
#include <iostream>

#define N 5

using namespace std;

bool checkSum(int a[N], int b[N], int c[N])
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			int k = 0;

			while(k < N && (a[i] + b[j] > c[k])) k++;

			if(a[i] + b[j] == c[k]) return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	// int a[N] = {11, 12, 13, 14, 15};
	// int b[N] = {3, 4, 7, 9, 9};
	// int c[N] = {1, 2, 6, 6, 7};

	int a[N] = {1, 1, 1, 4, 5};
	int b[N] = {1, 1, 2, 9, 9};
	int c[N] = {2, 5, 6, 6, 7};

	bool check = checkSum(a, b, c);

	cout << check << endl;

	return 0;
}
