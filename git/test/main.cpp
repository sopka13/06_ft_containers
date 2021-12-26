/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/23 09:01:47 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	print_binary(unsigned char *k, int size)
{
	for (int i = 0; i < size; ++i){
		printf(" (%d) ", (int)*k);
		printf("%d", (*k & 128) >> 7);
		printf("%d", (*k & 64) >> 6);
		printf("%d", (*k & 32) >> 5);
		printf("%d", (*k & 16) >> 4);

		printf("%d", (*k & 8) >> 3);
		printf("%d", (*k & 4) >> 2);
		printf("%d", (*k & 2) >> 1);
		printf("%d", (*k & 1) >> 0);

		printf(" ");
		// write(2, "|", 1);
		k += 1;
	}
	printf("\n");
}

int		main(int argc, char** argv){
	// Create my object
	std::map<int, int>	a;

	a.insert(std::pair<int, int>(1, 1));
	a.insert(std::pair<int, int>(2, 2));
	a.insert(std::pair<int, int>(3, 3));
	a.insert(std::pair<int, int>(4, 4));
	a.insert(std::pair<int, int>(5, 5));

	std::map<int, int>::iterator				f_01 = a.begin();
	std::map<int, int>::const_iterator			f_02 = a.begin();
	std::map<int, int>::reverse_iterator		f_03 = a.rend();
	std::map<int, int>::const_reverse_iterator	f_04 = a.rend();
	f_03--;
	f_04--;
	std::map<int, int>::iterator				f_011 = a.begin();
	std::map<int, int>::const_iterator			f_021 = a.begin();
	std::map<int, int>::reverse_iterator		f_031 = a.rend();
	std::map<int, int>::const_reverse_iterator	f_041 = a.rend();
	f_031--;
	f_041--;

	std::cout << f_01->first << " => " << f_01->second << std::endl;
	std::cout << f_02->first << " => " << f_02->second << std::endl;
	std::cout << f_03->first << " => " << f_03->second << std::endl;
	std::cout << f_04->first << " => " << f_04->second << std::endl;

	// iterator
	// const_iterator
	// reverse_iterator
	// const_reverse_iterator
	//
	// iterator | const_iterator
	// iterator | reverse_iterator
	// iterator | const_reverse_iterator
	//
	// const_iterator | reverse_iterator
	// const_iterator | const_reverse_iterator
	//
	// reverse_iterator | const_reverse_iterator

	std::cout << (int)(f_01 != f_011) << std::endl;
	std::cout << (int)(f_02 != f_021) << std::endl;
	std::cout << (int)(f_03 != f_031) << std::endl;
	std::cout << (int)(f_04 != f_041) << std::endl;

	std::cout << (int)(f_01 != f_02) << std::endl;
	// std::cout << (int)(f_01 != f_03) << std::endl;
	// std::cout << (int)(f_01 != f_04) << std::endl;

	// std::cout << (int)(f_02 != f_03) << std::endl;
	// std::cout << (int)(f_02 != f_04) << std::endl;

	std::cout << (int)(f_03 != f_04) << std::endl;

	// f_01 = f_011;
	// f_02 = f_021;
	// f_03 = f_031;
	// f_04 = f_041;

	// f_01 = f_02;
	// f_01 = f_03;
	// f_01 = f_04;

	// f_02 = f_01;
	// f_02 = f_03;
	// f_02 = f_04;

	// f_03 = f_01;
	// f_03 = f_02;
	// f_03 = f_04;

	// f_04 = f_01;
	// f_04 = f_02;
	// f_04 = f_03;
}