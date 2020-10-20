#include <iostream>

#include "dqueue.h"

int main(int argc, char const *argv[])
{
	DQueue<int> q1;

	for(int i = 0; i < 7; ++i)
	{
		q1.insert(i);
	}

	q1 = q1 + DQueue<int>(5);

	for(auto it = q1.begin(); it != q1.end(); ++it)
	{
		std::cout << *it << " " << std::endl;
	}

	return 0;
}
