/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/04 09:49:39 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(int argc, char** argv){
	// Create my object
	std::map<int, int>	a;

	// std::pair<std::map<int, int>::iterator, int> b = a.insert(std::pair<int, int>(5, 6));
	// std::map<int, int>::iterator c =  b.first;
	std::cout << "first = " << (*((a.insert(std::pair<int, int>(5, 6))).first)).first; //<< "; second = " << b.second << std::endl;
	std::map<int, int>::iterator f(a.begin());
	std::cout << (*(f)).first << std::endl;
}