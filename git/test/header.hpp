/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:45:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/27 23:58:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <unistd.h>

namespace ft{
	// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	template <typename Key, typename T>
	class map {
		template<typename T1, typename T2>
		class t_treeElem{
			t_treeElem(T1 key, T2 value): _key(key), _value(value), _left(NULL), _right(NULL) {}
			~t_treeElem(){}

		public:
			T1				_key;
			T2				_value;
			t_treeElem*		_left;
			t_treeElem*		_right;
		};
		
		t_treeElem<Key, T>*					_tree;
		std::allocator<t_treeElem<Key, T> >	allocator;
	
	public:
		map<Key, T>(): _tree(NULL) {}
		~map(){}

		std::allocator<t_treeElem<Key, T> >*		getAllocatorPointer() { return &allocator; }
	};
}