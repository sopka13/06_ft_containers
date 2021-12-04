/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:48:39 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/04 17:06:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Implement the following containers and turn in the necessary files
**	<container>.hpp
**	• You must also provide a main.cpp which tests everything for your evaluations.
**	(you need to go further than the example!)
**	• You must produce one binary with only your containers and one with the same
**	testing with STL containers.
**	• Compare outputs and timing (you can be up to 20 times slower).
**	• member functions, Non-member and overloads are expected.
**	• respect the naming, take care to details.
**	• You must use std::allocator.
**	• You must justify your inner data structure for each container (using a simple
**	array for a map is not ok).
**	• If the container has an iterator system, you must implement it.
**	• iterators_traits, reverse_iterator, enable_if, is_integral,
**	equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented.
**	• You can use https://www.cplusplus.com/ and https://cppreference.com/ as
**	references.
**	• You cannot implement more public functions than the ones offered in the standard
**	containers. Everything else must be private or protected. Each public function/-
**	variable must be justified.
**	• For non-member overloads, the keyword friend is allowed. Each use of friend must
**	be justified and will be checked during evaluation.
**	You must turn in the following containers and their associated functions:
**	• Vector
**	• Map
**	• Stack
**	Your stack will use your vector class as default underlaying container, it must
**	still be compatible with others containers like the STL one.
**	STL containers are forbidden.
**	You are allowed to use the STD library.
*/

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

	pair<const int, int> pr(5, 12);
	std::cout << (*((f.insert(pr)).first)).first << std::endl;
	pair<const int, int> pp(99, 18);
	f.insert(pp);

	printf("Return emty status: %d\n", f.empty());		// test empty function
	printf("Return size: %lu\n", f.size());				// test size function

	// ft::map<int, int>::iterator l;
	// std::allocator<int>* ll = new std::allocator<int>;
	// ll->deallocate()
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
