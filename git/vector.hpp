/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/09/03 14:54:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
	public:
		explicit vector( const Allocator& alloc = Allocator() );
		explicit vector( size_t count, const T& value = T(), const Allocator& alloc = Allocator());
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		vector( const vector& other);
		~vector();

		vector& operator=(const vector& other);

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
		size_t				size() const;
		size_t				max_size() const;
		void				reserve( size_t size );
		size_t				capacity() const;
		bool				empty() const;

		// Element access:
		T&					operator[]( size_t pos );
		const T&			operator[]( size_t pos ) const;
		T&					at( size_t pos );
		const T&			at( size_t pos ) const;
		T&		 			front();
		const T&			front() const;
		T&		 			back();
		const T&			back() const;
		T*					data();
		const T*			data() const;

		// Modifiers:
		void				assign( size_t count, const T& value );
		template< class InputIt >
		void				assign( InputIt first, InputIt last );
		void				push_back( const T& value );
		void				pop_back();
		iterator			insert( iterator pos, const T& value );
		void				insert( iterator pos, size_t count, const T& value );
		template< class InputIt >
		void				insert( iterator pos, InputIt first, InputIt last);
		iterator			erase( iterator pos );
		iterator			erase( iterator first, iterator last );
		void				swap( vector& other );
		void				clear();
		void				resize( size_t count, T value = T() );

		// Allocator:
		Allocator			get_allocator() const;
	};
	template<  >
	bool operator==( vector<>& lhs, vector<>& rhs );

	template<  >
	bool operator!=( vector<>& lhs, vector<>& rhs );

	template<  >
	bool operator<( vector<>& lhs, vector<>& rhs );

	template<  >
	bool operator<=( vector<>& lhs, vector<>& rhs );

	template<  >
	bool operator>( vector<>& lhs, vector<>& rhs );

	template<  >
	bool operator>=( vector<>& lhs, vector<>& rhs );
}