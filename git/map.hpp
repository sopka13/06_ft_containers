/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/24 23:23:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	1. Add binary three
*/

#pragma once

#include <iostream>
#include "source.hpp"

namespace ft {


	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		template<typename T1, typename T2>
		class t_treeElem{
			t_treeElem(T1 key, T2 value): _key(key), _value(value), _left(NULL), _right(NULL) {}
			~t_treeElem(){}

		public:
			T1				_key;
			T2				_value;
			t_treeElem*		_left;
			t_treeElem*		_right;
			t_treeElem*		_parent;
		};
		Allocator		_al;
		t_treeElem*		_tree;
		size_t			_size;
		
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
		template< class InputIterator >
		map( InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
		map( const map& other );
		~map();

		map& operator=( const map& other );

		// Iterators:
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		// Capacity:
		bool					empty() const {
			return if (_size) false; else true;
		}
		size_t				size() const {
			return _size;
		}
		size_t				max_size() const {
			long a = sysconf(_SC_PHYS_PAGES);
			long b = sysconf(_SC_PAGESIZE);
			long c = a * b;
			return static_cast<size_t>(c / sizeof(t_treeElem))
		}

		// Element access:
		T&						operator[]( const Key& key ){
			// need search by tree
		}
		T&						at( const Key& key ){
			// need search by tree
		}
		const T&				at( const Key& key ) const{
			// need search by tree
		}

		// Modifiers:
		pair<iterator,bool>			insert( const value_type& value ){
			
		}
		iterator					insert( iterator hint, const value_type& value );
		template< class InputIt >
		void						insert( InputIt first, InputIt last );
		void						erase( iterator position );
		void						erase( iterator first, iterator last );
		size_type					erase( const key_type& key );
		void						swap( map& other );
		void						clear();

		// Observers:
		key_compare					key_comp() const;
		map::value_compare			value_comp() const;

		// Operations:
		iterator					find( const Key& key );
		const_iterator				find( const Key& key ) const;
		size_type					count( const Key& key ) const;
		iterator					lower_bound( const Key& key );
		const_iterator				lower_bound( const Key& key ) const;
		iterator					upper_bound( const Key& key );
		const_iterator				upper_bound( const Key& key ) const;
		pair<iterator,iterator>				equal_range( const Key& key );
		pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;
	

		// Allocator:
		allocator_type				get_allocator() const{
			return alloc;
		}
	};

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator==( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs == rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator!=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs != rhs)
	}
	
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator<( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs < rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator<=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs <= rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator>( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs > rhs)
	}
	
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	bool operator>=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs >= rhs)
	}
}