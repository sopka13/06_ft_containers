/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:53 by eyohn             #+#    #+#             */
/*   Updated: 2021/09/03 14:54:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"s

namespace ft {
	template <class T, ft::vector<T>>
	class stack
	{
	public:
		explicit stack( const ft::vector<T>& cont = Container() );
		~stack();

		stack<T, ft::vector<T>>&	operator=( const stack<T,Container>& other );
		bool						empty() const;
		size_t						size() const;
		ft::vector<T>&				top();
		const ft::vector<T>&		top() const;
		void						push( const T& value );
		void						pop();
	};

	template<  >
	bool operator==( stack<>& lhs, stack<>& rhs );

	template<  >
	bool operator!=( stack<>& lhs, stack<>& rhs );

	template<  >
	bool operator<( stack<>& lhs, stack<>& rhs );

	template<  >
	bool operator<=( stack<>& lhs, stack<>& rhs );

	template<  >
	bool operator>( stack<>& lhs, stack<>& rhs );

	template<  >
	bool operator>=( stack<>& lhs, stack<>& rhs );
}