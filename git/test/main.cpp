/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:06 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/02 14:27:25 by eyohn            ###   ########.fr       */
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

	a.insert(std::pair<int, int>(1, 11));
	a.insert(std::pair<int, int>(2, 12));
	a.insert(std::pair<int, int>(3, 13));
	a.insert(std::pair<int, int>(4, 14));
	a.insert(std::pair<int, int>(5, 15));


	std::map<int, int>::iterator	it_01 = a.begin();
	std::map<int, int>::iterator	it_02 = a.end();
	while (it_01 != it_02) {
		std::cout << it_01->first << " => " << it_01->second << std::endl;
		it_01++;
	}

	std::map<int, int>::iterator	it = a.begin();
	it++;

	std::pair<int, int> b(99, 99);
	a.insert(it, b);

	// it_01 = a.begin();
	// it_02 = a.end();
	// while (it_01 != it_02){
	// 	std::cout << it_01->first << " => " << it_01->second << std::endl;
	// 	it_01++;
	// }

	std::map<int, int> bb(a);
	a.clear();
	std::cout << " Size = " << bb.size() << std::endl;

	int ll = a.at(1);
	std::cout << "Value = " << ll << std::endl;
}