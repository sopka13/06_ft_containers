/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/26 15:44:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	1. Add binary three
*/

#pragma once

#include <iostream>
#include <unistd.h>
#include "source.hpp"

namespace ft {

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
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
		Allocator				_al;
		t_treeElem<Key, T>*		_tree;
		size_t					_size;
		Compare					_comp;
		
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() );//:
		// 	_al(alloc),
		// 	_tree(NULL),
		// 	_size(0),
		// 	_comp(comp)
		// {
		// 	std::cout << sizeof(_al) << std::endl;
		// 	// _al = alloc;
		// 	std::cout << sizeof(_al) << std::endl;
		// 	std::cout << "Constructor map start" << std::endl;
		// }
		// template< class InputIterator >
		// map( InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			
		// map( const map& other );
		~map(){
			std::cout << "Destructor map start" << std::endl;
		}

		// map& operator=( const map& other );

		// Iterators:
		// iterator				begin();
		// const_iterator			begin() const;
		// iterator				end();
		// const_iterator			end() const;
		// reverse_iterator		rbegin();
		// const_reverse_iterator	rbegin() const;
		// reverse_iterator		rend();
		// const_reverse_iterator	rend() const;

		// Capacity:
		bool					empty() const {
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

		// Element access:
		// T&						operator[]( const Key& key ){
		// 	// need search by tree
		// }
		// T&						at( const Key& key ){
		// 	// need search by tree
		// }
		// const T&				at( const Key& key ) const{
		// 	// need search by tree
		// }

		// // Modifiers:
		void /*pair<iterator,bool>*/			insert( const pair<const Key, T>& value ){
			// if (_size) {
			// 	if (_comp(value.first))
			// }
			// else {
				if (_comp(value.first, _tree->_key)) // < == > 
				// _tree = _al.allocate(1);
				_fff = _al.allocate(sizeof(value));
				// _tree = new t_treeElem<Key, T>(value);
				if (_tree) _size++;
			// }
		}
		// iterator					insert( iterator hint, const value_type& value );
		// template< class InputIt >
		// void						insert( InputIt first, InputIt last );
		// void						erase( iterator position );
		// void						erase( iterator first, iterator last );
		// size_type					erase( const key_type& key );
		// void						swap( map& other );
		// void						clear();

		// Observers:
		// key_compare					key_comp() const;
		// map::value_compare			value_comp() const;

		// Operations:
		// iterator					find( const Key& key );
		// const_iterator				find( const Key& key ) const;
		// size_type					count( const Key& key ) const;
		// iterator					lower_bound( const Key& key );
		// const_iterator				lower_bound( const Key& key ) const;
		// iterator					upper_bound( const Key& key );
		// const_iterator				upper_bound( const Key& key ) const;
		// pair<iterator,iterator>				equal_range( const Key& key );
		// pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;
	

		// Allocator:
		Allocator				get_allocator() const{
			return _al;
		}
	};

	template <class Key, class T, class Compare, class Allocator>
	bool operator==( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs == rhs);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs != rhs);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator<( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs < rhs);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs <= rhs);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs > rhs);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator>=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs >= rhs);
	}
}