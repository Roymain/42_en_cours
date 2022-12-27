
#include "map.hpp"
#include <map>
#include <string>
#include <string.h>

int main(){

	ft::map<int, std::string> test;

	std::string test2 = "bernard";
	std::string ro = "roger";

	int num = 128;
	int num2 = 152;
	std::string lu = "amen";
	test.insert(ft::pair<int, std::string>(201, "ami"));
	test.insert(ft::make_pair(100, "amen"));
	test.insert(ft::make_pair(num2, "rvfsgre"));
	test.insert(ft::make_pair(-2, "aens"));
	test.insert(ft::make_pair(151, "am"));
	test.insert(ft::make_pair(199, "amis"));
	test.insert(ft::make_pair(170, ro));
	test.insert(ft::make_pair(22, "ajbkj"));
	test.insert(ft::make_pair(num, "ro"));
	//VERIF
	//char* verif = strdup("roger");


	test.erase(199);



// 	std::cout << "erase done\n";
// 	std::cout << test.begin().getNodePtr()->content.first << "      "  << test.max_size() << std::endl;
// 	// std::cout << "humhum" << test.getRoot()->content.first << std::endl;

	std::cout << test[22] << std::endl;

	ft::map<int, std::string>::iterator it = test.begin();


	std::cout << it->second << " " << it->first << std::endl;
	it++;
//	std::cout << it->first << std::endl;

	--it;
	// --it;
	// --it;
	// --it;
	// --it;
	// --it;
	// --it;
	// --it;
	// printf("=>%d.\n", it.getNodePtr()->content.first );
	// --it;
	// --it;
	// --it;
	// printf("=>%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("=>%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("=>%d\n", it.getNodePtr()->content.first );
	// --it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// ++it;
	// ++it;
	// ++it;
	// ++it;
	// ++it;
	// ++it;
	// ++it;
	// ++it;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it++;
// 	 printf("==>%d\n", it.getNodePtr()->content.first );
// 	it--;
// 	printf("==> - = %d\n", it.getNodePtr()->content.first );
// 	--it;
// 	printf("==>%d\n", it.getNodePtr()->content.first );
	// --it;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// --it;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// std::cout << "size = " << test.size() << std::endl;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// printf("==>%d\n", it.getNodePtr()->content.first );
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it--;
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;
	// printf("%d\n", it.getNodePtr()->content.first );
	// it++;


	// std::vector<std::string> test;

	// std::cout << test << std::endl;

	// test.insert(std::pair<int, std::string> (152, "haha"));
	// test.insert(std::pair<int, std::string> (100, "haha"));
	// test.insert(std::pair<int, std::string> (128, "haha"));
	// test.insert(std::pair<int, std::string> (170, "haha"));
 	// std::cout << test[33] << std::endl;

	// std::map<int, std::string>::iterator it = test.end();
	// std::cout << (*it).first << std::endl;
	// it--;
	// std::cout << (*it).first << std::endl;
	// it--;
	// std::cout << (*it).first << std::endl;
	// it--;
	// std::cout << (*it).first << std::endl;
	// it--;
	// //std::cout << (*it).first << std::endl;
	// it--;





	return (0);
}