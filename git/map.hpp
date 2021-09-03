/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/09/03 14:54:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 4. Check all question about subject
*/

#pragma once

#include <iostream>

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> >>
	class map
	{
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
		std::pair<iterator,bool>	insert( const value_type& value );
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
		std::map::value_compare		value_comp() const;

		// Operations:
		iterator					find( const Key& key );
		const_iterator				find( const Key& key ) const;
		size_type					count( const Key& key ) const;
		iterator					lower_bound( const Key& key );
		const_iterator				lower_bound( const Key& key ) const;
		iterator					upper_bound( const Key& key );
		const_iterator				upper_bound( const Key& key ) const;
		std::pair<iterator,iterator>				equal_range( const Key& key );
		std::pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;
	

		// Allocator:
		allocator_type				get_allocator() const;
	};

	template<  >
	bool operator==( map<>& lhs, map<>& rhs );

	template<  >
	bool operator!=( map<>& lhs, map<>& rhs );
	
	template<  >
	bool operator<( map<>& lhs, map<>& rhs );

	template<  >
	bool operator<=( map<>& lhs, map<>& rhs );

	template<  >
	bool operator>( map<>& lhs, map<>& rhs );
	
	template<  >
	bool operator>=( map<>& lhs, map<>& rhs );
}