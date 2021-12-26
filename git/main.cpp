/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:48:39 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/26 15:28:28 by eyohn            ###   ########.fr       */
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

	//------Constructors------
	{
		std::cout << "\n Constructors test start" << std::endl;

		ft::map<int, int> map_01;
		// ft::map<int, int> map_02(map_01);
		// ft::map<int, int> map_03(map_01.find(3), map_01.end());
	}
	//------Destructor--------
	{
		std::cout << "\n Destructor test start" << std::endl;

		ft::map<int, int> map_01;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		// ft::map<int, int>::iterator it = map_01.begin();
		// std::cout << (*it).second << std::endl;
		map_01.insert(p3);
		// map_01.~map();										//sega
	}
	//------Element access----
	{
		std::cout << "\n Element access test start" << std::endl;
	}
	//------Modifiers---------
	{
		std::cout << "\n Modifiers test start" << std::endl;

		ft::map<int, int> map_01;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		// ft::map<int, int>::iterator it_01 = map_01.begin();
		// map_01.erase(it);
		// ft::map<int, int>::iterator it_02 = map_01.begin();
		// ft::map<int, int>::iterator it_03 = map_01.end();
		// map_01.erase(it_02, it_03);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		// map_01.erase(1);
		// map_01.erase(2);
		// map_01.erase(3);
	}
	//------Iterators---------
	{
		std::cout << "\n Iterators test start" << std::endl;

		ft::map<int, int> map_01;
		pair<const int, int> p1(9, 11);
		pair<const int, int> p2(99, 12);
		pair<const int, int> p3(3, 13);
		pair<const int, int> p4(5, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		map_01.insert(p4);

		// for (int i = 0; i < 100; ++i){
		// 	pair<const int, int> p(rand(), i);
		// 	map_01.insert(p);
		// }

		// printf("Current size: %lu\n", map_01.size());

		ft::map<int, int>::iterator					it_01 = map_01.begin();
		ft::map<int, int>::iterator					it_02 = map_01.end();
		// it_01->first = 933;
		it_01->second = 933;
		while (it_01 != it_02){
			std::cout << it_01->first << " => " << it_01->second << std::endl;
			it_01++;
		}

		// it_01 = map_01.begin();
		// it_02 = map_01.end();
		// while (it_02 != it_01){
		// 	it_02--;
		// 	std::cout << it_02->first << " => " << it_02->second << std::endl;
		// }
	
		ft::map<int, int>::const_iterator			it_03 = map_01.begin();
		ft::map<int, int>::const_iterator			it_04 = map_01.end();
		// it_03->first = 933;
		// it_03->second = 933;
		while (it_03 != it_04){
			std::cout << it_03->first << " => " << it_03->second << std::endl;
			it_03++;
		}
		// ft::map<int, int>::const_iterator			it_04 = map_01.end();
		// ft::map<int, int>::reverse_iterator			it_05 = map_01.rbegin();
		// ft::map<int, int>::reverse_iterator			it_07 = map_01.rend();
		// ft::map<int, int>::const_reverse_iterator	it_06 = map_01.rbegin();
		// ft::map<int, int>::const_reverse_iterator	it_08 = map_01.rend();
	}
	//------Observers---------
	{
		std::cout << "\n Observers test start" << std::endl;

		ft::map<int, int> map_01;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);

		// ft::map<int, int>::key_compare my_compare = map_01.key_comp();
		// int max_elem = 3;
		// ft::map<int, int>::iterator it = map_01.begin();
		// do {
		// 	std::cout << it->first << " => " << it->second << std::endl;
		// } while (my_compare((*it++).first ,max_elem));

		// ft::pair<int, int> max_elem = *map_01.rbegin();
		// it = map_01.begin();
		// do {
		// 	std::cout << it->first << " => " << it->second << std::endl;
		// } while (map_01.value_comp()(*it++, max_elem));
	}
	//------Capacity----------
	{
		std::cout << "\n Capacity test start" << std::endl;

		ft::map<int, int> map_01;
		std::cout << "Map empty: " <<		map_01.empty() << std::endl;
		std::cout << "Map size: " <<		map_01.size() << std::endl;
		std::cout << "Map max_size: " <<	map_01.max_size() << std::endl;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		std::cout << "Map empty: " <<		map_01.empty() << std::endl;
		std::cout << "Map size: " <<		map_01.size() << std::endl;
		std::cout << "Map max_size: " <<	map_01.max_size() << std::endl;
	}
	//------Operations--------
	{
		std::cout << "\n Operations test start" << std::endl;

		ft::map<int, int> map_01;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);

		// ft::map<int, int>						it_01 = map_01.find(2);
		// ft::map<int, int>::const_iterator		it_02 = map_01.find(2);
		// size_t									val_01 = map_01.count(2);
		// ft::map<int, int>::iterator				it_03 = map_01.lower_bound(2);
		// ft::map<int, int>::const_iterator		it_04 = map_01.lower_bound(2);
		// ft::map<int, int>::iterator				it_05 = map_01.upper_bound(2);
		// ft::map<int, int>::const_iterator		it_06 = map_01.upper_bound(2);
		// ft::pair<iterator,iterator>				p_01 = map_01.equal_range(2);
		// ft::pair<const_iterator,const_iterator>	p_02 = map_01.equal_range(2);
	}
	//------Operators---------
	{
		std::cout << "\n Operators test start" << std::endl;

		ft::map<int, int> map_01;
		ft::map<int, int> map_02;
		pair<const int, int> p1(1, 11);
		pair<const int, int> p2(2, 12);
		pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		pair<const int, int> p11(1, 11);
		pair<const int, int> p21(2, 12);
		pair<const int, int> p31(3, 13);
		map_02.insert(p11);
		map_02.insert(p21);
		map_02.insert(p31);

		// std::cout << "Comapare '==' : " << map_01 == map_02 << std::endl;
		// std::cout << "Comapare '!=' : " << map_01 != map_02 << std::endl;
		// std::cout << "Comapare '<' : " << map_01 < map_02 << std::endl;
		// std::cout << "Comapare '<=' : " << map_01 <= map_02 << std::endl;
		// std::cout << "Comapare '>' : " << map_01 > map_02 << std::endl;
		// std::cout << "Comapare '>=' : " << map_01 >= map_02 << std::endl;
	}
	//------Allocator---------
	{
		std::cout << "\n Allocator test start" << std::endl;
	}
	// Test my map container
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

	// ft::map<int, int> f;
	// printf("Return emty status: %d\n", f.empty());		// test empty function
	// printf("Return size: %lu\n", f.size());				// test size function
	// printf("Return max_size: %lu\n", f.max_size());		// test max_size function

	// printf("Return emty status: %d\n", f.empty());		// test empty function
	// printf("Return size: %lu\n", f.size());				// test size function

	// pair<const int, int> p1(0, 0);
	// std::cout << (*((f.insert(p1)).first)).first << std::endl;
	// pair<const int, int> p2(-1, 1);
	// f.insert(p2);
	// pair<const int, int> p3(-2, 2);
	// f.insert(p3);
	// pair<const int, int> p4(-2, 2);
	// f.insert(p4);
	// pair<const int, int> p5(-3, 3);
	// f.insert(p5);
	// pair<const int, int> p6(-4, 4);
	// f.insert(p6);
	// pair<const int, int> p7(-5, 5);
	// f.insert(p7);

	// printf("Return emty status: %d\n", f.empty());		// test empty function
	// printf("Return size: %lu\n", f.size());				// test size function

	
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
