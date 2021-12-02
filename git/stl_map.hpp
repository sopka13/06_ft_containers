/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_map.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/30 23:34:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unistd.h>
#include "source.hpp"

namespace ft {
	template<typename T1, typename T2>
	class t_treeElem {

	public:
		t_treeElem(const pair<const T1, T2>& value):
			_key(value.first),
			_value(value.second),
			_left(NULL),
			_right(NULL),
			_parent(NULL)
		{}
		~t_treeElem(){}

		T1				_key;
		T2				_value;
		t_treeElem*		_left;
		t_treeElem*		_right;
		t_treeElem*		_parent;
	};

	template <class Key, class T, class Compare = less<Key>,
				class Allocator = std::allocator<t_treeElem<Key, T> > >
	class map
	{
		t_treeElem<Key, T>*	_tree;
		Compare				_compare;
		Allocator			_al;
		size_t				_size;

	public:
		typedef Allocator	allocator_type;
		typedef Compare		key_compare;
		
		explicit map (const key_compare& comp = Compare(), const allocator_type& alloc = Allocator()):
			_tree(NULL),
			_compare(comp),
			_al(alloc),
			_size(0)
		{}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());

		// map (const map& x);

		~map(){
			std::cout << "Destructor map start" << std::endl;
		}

		void /*pair<iterator,bool>*/			insert( const pair<const Key, T>& value ){
			_tree = _al.allocate(1);				// allocate memory for 1 element
			_al.construct(_tree, value);			// construct element
			std::cout << _tree->_key << std::endl;	// show first key
			_size++;								// ++ size tree
		}

		// Capacity:
		bool				empty() const {
			return (_size) ? false : true;
		}
		size_t				size() const {
			return _size;
		}
		size_t				max_size() const {
			long a = sysconf(_SC_PHYS_PAGES);
			long b = sysconf(_SC_PAGESIZE);
			long c = a * b;
			return static_cast<size_t>(c / sizeof(t_treeElem<Key, T>));
		}
	};
}