
#include "map.hpp"
#include <map>
#include <string>
#include <string.h>

#include <unistd.h>
int main(){

	  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;


  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);
	std::cout << "huu\n";
  int psize;
    ft::pair<const char,int>* p;
p = mymap.get_allocator().allocate(6);
 psize = sizeof(ft::map<char,int>::value_type)*5;
 mymap.get_allocator().deallocate(p,5);
  // print content:
   std::cout << "elements" << psize << "in mymap:" << p << '\n';
//   std::cout << "a => " << mymap.find('b')->second << '\n';
//   std::cout << "c => " << mymap.find('c')->second << '\n';
//   std::cout << "d => " << mymap.find('d')->second << '\n';




	// ft::map<int, std::string> test;

	// std::string test2 = "bernard";
	// std::string ro = "roger";

	// int num = 128;
	// int num2 = 152;
	// std::string lu = "amen";
	// test.insert(ft::pair<int, std::string>(201, "ami"));
	// test.insert(ft::make_pair(100, "amen"));
	// test.insert(ft::make_pair(num2, "rvfsgre"));
	// test.insert(ft::make_pair(-2, "aens"));
	// test.insert(ft::make_pair(151, "am"));
	// test.insert(ft::make_pair(199, "amis"));
	// test.insert(ft::make_pair(170, ro));
	// test.insert(ft::make_pair(22, "ajbkj"));
	// test.insert(ft::make_pair(num, "ro"));
	// //VERIF
	// //char* verif = strdup("roger");

	// ft::map<int, std::string>::iterator it = test.find(201);

 	// if (it != test.end())
   	// 	test.erase (it); std::cout << "haha\n";


	// std::cout << test.find(-2)->second << std::endl;
	// std::cout << test.find(199)->second << std::endl;
	// std::cout << test.find(170)->second << std::endl;

	// // for (; it != test.end(); ++it){
	// 	std::cout << "=>" << it->first << std::endl;
// 	// };



// 	// for (; it != test.begin(); ++it){
// 	// 	std::cout << it->first << std::endl;
// 	// };

// while (!test.empty())
//   {
//     std::cout << "crgwegwe\n" << test.begin()->first << " => " << '\n';
//     test.erase(test.begin());
// 	std::cout << "done" << test.empty() << "\n";
	
//   //  std::cout << "crgwegwe\n" << test.begin()->first << " => " << '\n';
//   }

	//test.erase(199);




// 	std::cout << "erase done\n";
// 	std::cout << test.begin().getNodePtr()->content.first << "      "  << test.max_size() << std::endl;
// 	// std::cout << "humhum" << test.getRoot()->content.first << std::endl;

// 	std::cout << test[22] << std::endl;

// 	ft::map<int, std::string>::iterator it = test.begin();


// 	std::cout << it->second << " " << it->first << std::endl;
// 	it++;
// //	std::cout << it->first << std::endl;

// 	--it;
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


// 	std::map<int , std::string> test;

// //	std::cout << test << std::endl;

// 	test.insert(std::pair<int, std::string> (152, "haha"));
// 	test.insert(std::pair<int, std::string> (100, "haha"));
// 	test.insert(std::pair<int, std::string> (128, "haha"));
// 	test.insert(std::pair<int, std::string> (170, "haha"));
//  	//std::cout << test[33] << std::endl;

// 	std::map<int, std::string>::iterator it = test.begin();
// 	for (; it != test.end(); it++){
// 		std::cout << "=>" << it->first << std::endl;
// 	};
// 	it--;
// 	for (; it != test.begin(); it--){
// 		std::cout << it->first << std::endl;
// 	};

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