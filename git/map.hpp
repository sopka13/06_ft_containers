/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/27 22:45:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 4. Check all question about subject
*/

#pragma once

#include <iostream>

namespace ft {
	class map
	{
	public:
		map();
		~map();

		map& operator= (const map &);

		// Iterators:
		// begin
		// end
		// rbegin
		// rend
		// cbegin
		// cend
		// crbegin
		// crend

		// Capacity:
		// empty
		// size
		// max_size

		// Element access:
		// operator[]
		// at

		// Modifiers:
		// insert
		// erase
		// swap
		// clear
		// emplace
		// emplace_hint

		// Observers:
		// key_comp
		// value_comp

		// Operations:
		// find
		// count
		// lower_bound
		// upper_bound
		// equal_range

		// Allocator:
		// get_allocator
	};
}