#include <iostream>
#include <string>
#include <deque>
#ifndef CHECK  
#define CHECK 1
#endif

	// #include <map>
	// #include <stack>
	// #include <vector>
	// namespace ft = std;

	#include "map.hpp"
	#include "../Stack.hpp"
	#include "../vector/Vector.hpp"



int main(){
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;


  ft::pair<char,int> highest = *mymap.rend();          // last element
  std::cout << "mymap contains:\n";

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

return 0;
}



// 										MAIN
// #include <stdlib.h>
// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		return 1;
// 	}
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < 50; ++i)
// 	{
// 		int i1 = rand() % seed;
// 		int i2 = rand() % seed;
// 		map_int.insert(ft::make_pair(i1, i2));
// 		std::cout << "_int = " << i1 << "\n";
// 	}
// 	std::cout << map_int.begin()->first << std::endl;
// 	int sum = 0;
// 	for (int i = 0; i < 50; i++)
// 	{
// 		int access = rand()  % seed;
// 		sum += map_int[access];
// 		std::cout << "map_int = " << map_int[access] << "\n";
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy;
// 		copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }








// #include "map.hpp"
// #include <map>
// #include <string>
// #include <string.h>

// #include <unistd.h>
// int main(){

// 	  ft::map<char,int> mymap;
//   ft::map<char,int>::iterator it;


//   it = mymap.find('b');
//   if (it != mymap.end())
//     mymap.erase (it);
// 	std::cout << "huu\n";
//   int psize;
//     ft::pair<const char,int>* p;
// p = mymap.get_allocator().allocate(6);
//  psize = sizeof(ft::map<char,int>::value_type)*5;
//  mymap.get_allocator().deallocate(p,5);
//   // print content:
//    std::cout << "elements" << psize << "in mymap:" << p << '\n';
// //   std::cout << "a => " << mymap.find('b')->second << '\n';
// //   std::cout << "c => " << mymap.find('c')->second << '\n';
// //   std::cout << "d => " << mymap.find('d')->second << '\n';




// 	// ft::map<int, std::string> test;

// 	// std::string test2 = "bernard";
// 	// std::string ro = "roger";

// 	// int num = 128;
// 	// int num2 = 152;
// 	// std::string lu = "amen";
// 	// test.insert(ft::pair<int, std::string>(201, "ami"));
// 	// test.insert(ft::make_pair(100, "amen"));
// 	// test.insert(ft::make_pair(num2, "rvfsgre"));
// 	// test.insert(ft::make_pair(-2, "aens"));
// 	// test.insert(ft::make_pair(151, "am"));
// 	// test.insert(ft::make_pair(199, "amis"));
// 	// test.insert(ft::make_pair(170, ro));
// 	// test.insert(ft::make_pair(22, "ajbkj"));
// 	// test.insert(ft::make_pair(num, "ro"));
// 	// //VERIF
// 	// //char* verif = strdup("roger");

// 	// ft::map<int, std::string>::iterator it = test.find(201);

//  	// if (it != test.end())
//    	// 	test.erase (it); std::cout << "haha\n";


// 	// std::cout << test.find(-2)->second << std::endl;
// 	// std::cout << test.find(199)->second << std::endl;
// 	// std::cout << test.find(170)->second << std::endl;

// 	// // for (; it != test.end(); ++it){
// 	// 	std::cout << "=>" << it->first << std::endl;
// // 	// };



// // 	// for (; it != test.begin(); ++it){
// // 	// 	std::cout << it->first << std::endl;
// // 	// };

// // while (!test.empty())
// //   {
// //     std::cout << "crgwegwe\n" << test.begin()->first << " => " << '\n';
// //     test.erase(test.begin());
// // 	std::cout << "done" << test.empty() << "\n";
	
// //   //  std::cout << "crgwegwe\n" << test.begin()->first << " => " << '\n';
// //   }

// 	//test.erase(199);




// // 	std::cout << "erase done\n";
// // 	std::cout << test.begin().getNodePtr()->content.first << "      "  << test.max_size() << std::endl;
// // 	// std::cout << "humhum" << test.getRoot()->content.first << std::endl;

// // 	std::cout << test[22] << std::endl;

// // 	ft::map<int, std::string>::iterator it = test.begin();


// // 	std::cout << it->second << " " << it->first << std::endl;
// // 	it++;
// // //	std::cout << it->first << std::endl;

// // 	--it;
// 	// --it;
// 	// --it;
// 	// --it;
// 	// --it;
// 	// --it;
// 	// --it;
// 	// --it;
// 	// printf("=>%d.\n", it.getNodePtr()->content.first );
// 	// --it;
// 	// --it;
// 	// --it;
// 	// printf("=>%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("=>%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("=>%d\n", it.getNodePtr()->content.first );
// 	// --it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// ++it;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it++;
// // 	 printf("==>%d\n", it.getNodePtr()->content.first );
// // 	it--;
// // 	printf("==> - = %d\n", it.getNodePtr()->content.first );
// // 	--it;
// // 	printf("==>%d\n", it.getNodePtr()->content.first );
// 	// --it;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// --it;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// std::cout << "size = " << test.size() << std::endl;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// printf("==>%d\n", it.getNodePtr()->content.first );
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it--;
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;
// 	// printf("%d\n", it.getNodePtr()->content.first );
// 	// it++;


// // 	std::map<int , std::string> test;

// // //	std::cout << test << std::endl;

// // 	test.insert(std::pair<int, std::string> (152, "haha"));
// // 	test.insert(std::pair<int, std::string> (100, "haha"));
// // 	test.insert(std::pair<int, std::string> (128, "haha"));
// // 	test.insert(std::pair<int, std::string> (170, "haha"));
// //  	//std::cout << test[33] << std::endl;

// // 	std::map<int, std::string>::iterator it = test.begin();
// // 	for (; it != test.end(); it++){
// // 		std::cout << "=>" << it->first << std::endl;
// // 	};
// // 	it--;
// // 	for (; it != test.begin(); it--){
// // 		std::cout << it->first << std::endl;
// // 	};

// 	// std::cout << (*it).first << std::endl;
// 	// it--;
// 	// std::cout << (*it).first << std::endl;
// 	// it--;
// 	// std::cout << (*it).first << std::endl;
// 	// it--;
// 	// std::cout << (*it).first << std::endl;
// 	// it--;
// 	// //std::cout << (*it).first << std::endl;
// 	// it--;





// 	return (0);
// }