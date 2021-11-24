/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/24 23:12:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(int argc, char** argv){
	// Create my object
	// ft::map<int, int>	a;

	// Return pointer to an allocator
	// std::allocator<ft::map<int, int> >* f = a.getAllocatorPointer();
	
	// Allocate memory for
	// ft::map<int, int>* pointer = f->allocate(sizeof(ft::map<int, int>));
	long a = sysconf(_SC_PHYS_PAGES);
	long b = sysconf(_SC_PAGESIZE);
	long c = a * b;
	printf("Free pages = %ld; page size = %ld; free memory = %lld\n", a, b, c);
	std::map<int, int> ff;
	printf("Max size = %lu\n", ff.max_size());
}