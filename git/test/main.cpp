/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/17 23:03:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
// #include <iostream>
#include <map>

int		main(int argc, char** argv){
	std::map<int, int>	a;
	// a.insert({1, 133});

	printf("!");
	printf("ret = %d", a.operator[](1));
}