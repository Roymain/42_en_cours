#include "Vector.hpp"
#include "VectorIterator.hpp"

int main(){
	
	ft::vector<int>		vect;
	ft::VectorIterator<int>	it;

	vect.resize(20);
	printf("%lu\n", vect.capacity());
	printf("%lu\n", vect.size());

	for (int i = 0; i < 10; i++)
		vect.push_back(i);

	for (it = vect.begin(); it != vect.end(); it++)
		printf("%d\n", *it);

	vect.pop_back();
	for (it = vect.begin(); it != vect.end(); it++)
		printf("%d\n", *it);

	printf("%lu lol\n", vect.size());
	return (0);
}