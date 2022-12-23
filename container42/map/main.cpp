
#include "map.hpp"
#include <string>
#include <map>

int main(){

	ft::map<int, std::string> test;

	std::string test2 = "bernard";
	std::string ro = "roger";

	int num = 128;
	int num2 = 152;
	int a = -2;
	std::string lu = "amen";
	test.insert(ft::make_pair(201, "ami"));
	test.insert(ft::make_pair(100, "amen"));
	test.insert(ft::make_pair(num2, "rvfsgre"));
	test.insert(ft::make_pair(-2, "aens"));
	test.insert(ft::make_pair(151, "am"));
	test.insert(ft::make_pair(199, "amis"));
	test.insert(ft::make_pair(170, "amiens"));
	test.insert(ft::make_pair(num, ro));
	test.insert(ft::make_pair(22, "a"));
	test.erase(152);


	std::cout << test.begin().getNodePtr()->content.first << "      "  << test.max_size() << std::endl;
	// std::cout << "humhum" << test.getRoot()->content.first << std::endl;
	
	ft::map<int, std::string>::iterator it = test.begin();
	printf("=>%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	printf("%d\n", it.getNodePtr()->content.first );
	it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// //printf("~~~%d\n", it.getNodePtr()->right->left->right->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("-%d\n", it.getNodePtr()->content.first );
	// it--;
	// it--;
	// it--;
	//it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;

	// std::map<int, std::string> test;

	// test.insert(std::pair<int, std::string> (152, "haha"));
	// test.insert(std::pair<int, std::string> (100, "haha"));
	// test.insert(std::pair<int, std::string> (128, "haha"));
	// test.insert(std::pair<int, std::string> (170, "haha"));

	// std::map<int, std::string>::iterator it = test.begin();
	// std::cout << (*it).first << std::endl;
	// it++;
	// std::cout << (*it).first << std::endl;
	// it++;
	// std::cout << (*it).first << std::endl;
	// it++;
	// std::cout << (*it).first << std::endl;
	// it++;
	// // std::cout << (*it).first << std::endl;
	// // it++;





	return (0);
}