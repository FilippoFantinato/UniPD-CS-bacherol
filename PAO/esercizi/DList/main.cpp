#include <iostream>

#include "DList.h"

int main(int argc, char const *argv[])
{
	DList<int> x(4,2), y(0,0), z(6,8);
	y = x;
	x.insertFront(-2); z.insertFront(3); y.insertFront(0);
	if(x<y) std::cout << "x < y" << std::endl;
	if(z<x) std::cout << "z < x" << std::endl;
	if(y<z) std::cout << "y < z" << std::endl;
	if(z<y) std::cout << "z < y" << std::endl;

	std::cout << "x= ";

	DList<int>::ConstIterator j = --(x.end());
	
	for(; j != x.begin(); --j)
	{
		std::cout << *j << ' ';
	}

	std::cout << *j << std::endl << "y= ";
	
	for(DList<int>::ConstIterator k = y.begin(); k != y.end(); ++k)
	{
		std::cout << *k << ' ';  
	}
	
	std::cout << std::endl << "z= ";
	
	DList<int>::ConstIterator i = z.begin(); 
	for( ; i != z.end(); ++i)
	{
		std::cout << *i << ' ';  
	}
	std::cout << std::endl;	
	return 0;
}