#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	// namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif


#include "stl_map.hpp"
#include "source.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include <stdio.h>

int		main(void) {

	// Test my map container
	ft::map<int, int> f;																// create my map copy
	// // std::cout << "1" << std::endl;
	// std::allocator<pair<const int, int> > aloc = f.get_allocator();						// get allocator test function
	// // std::cout << "2" << std::endl;
	// pair<const int, int>* pointer = aloc.allocate(sizeof(pair<const int, int>));		// use allocator pointer
	// // std::cout << "3" << std::endl;
	// ft::map<const int, int>* ff = new (pointer) ft::map<const int, int>;				// start constructor at the adress
	// // std::cout << "4" << std::endl;
	// std::allocator<pair<const int, int> > pp = ff->get_allocator();						// get allocator from object
	// // std::cout << "5" << std::endl;
	// ff->~map();																			// start destructor
	// // std::cout << "6" << std::endl;
	// aloc.deallocate(pointer, sizeof(pair<const int, int>));								// free memory
	// // std::cout << "7" << std::endl;

	printf("Return emty status: %d\n", f.empty());		// test empty function
	printf("Return size: %lu\n", f.size());				// test size function
	printf("Return max_size: %lu\n", f.max_size());		// test max_size function

	pair<const int, int> pr = { 1, 2 };
	f.insert(pr);

	printf("Return emty status: %d\n", f.empty());		// test empty function
	printf("Return size: %lu\n", f.size());				// test size function
	return 0;
}








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
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
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
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
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
