#include "Map.hpp"
#include <string>

int main(){

	ft::map<std::string, int> test;

	std::string ro = "roger";
	test.insert(ft::make_pair(ro, 125));
	
	ft::MapIterator it = test.begin();
	printf((*it)->first);


	return (0);
}