/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/31 13:37:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {
	template <typename T>
	class vector
	{
	public:
		vector(T; );
		~vector();

		vector& operator=(const vector &);

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
		// size
		// max_size
		// resize
		// capacity
		// empty
		// reserve
		// shrink_to_fit

		// Element access:
		// operator[]
		// at
		// front
		// back
		// data

		// Modifiers:
		// assign
		// push_back
		// pop_back
		// insert
		// erase
		// swap
		// clear
		// emplace
		// emplace_back

		// Allocator:
		// get_allocator
	};
}