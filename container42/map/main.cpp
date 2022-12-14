#include "Map.hpp"

#include <string>

int main(){

	ft::map<int, std::string> test;

	std::string test2 = "bernard";
	std::string ro = "roger";


	int num = 128;
	int num2 = 152;
	test.insert(ft::make_pair(num2, test2));
	test.insert(ft::make_pair(100, "amen"));
	test.insert(ft::make_pair(num, ro));
	test.insert(ft::make_pair(170, "amiens"));
	
	ft::map<int, std::string>::iterator it = test.begin();
	printf("=>%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );


	return (0);
}