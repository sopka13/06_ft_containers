/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/17 22:25:44 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	1. Add binary three
*/

#pragma once

#include <iostream>
#include "source.hpp"


namespace ft {


	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
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
		};
		
		
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
		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const;

		// Element access:
		T&						operator[]( const Key& key );
		T&						at( const Key& key );
		const T&				at( const Key& key ) const;

		// Modifiers:
		pair<iterator,bool>	insert( const value_type& value );
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

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator==( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs == rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator!=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs != rhs)
	}
	
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator<( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs < rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator<=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs <= rhs)
	}

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator>( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs > rhs)
	}
	
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T>> >
	bool operator>=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs >= rhs)
	}
}