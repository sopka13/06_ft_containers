/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <eyohn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:53 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/05 15:13:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack
	{
		ft::vector<T>		_cont;
	public:
		explicit stack( const ft::vector<T>& cont = Container() ) : _cont(cont) {};
		~stack();

		typedef ft::vector<T>		container_type;

		stack<T, ft::vector<T> >&	operator=( const stack<T,Container>& other );
		bool						empty() const{
			return _cont.empty();
		}
		size_t						size() const{
			return _cont.size();
		}
		vector<T>&					top(){
			return _cont.back();
		}
		const ft::vector<T>&		top() const{
			return _cont.back();
		}
		void						push( const T& value ){
			return _cont.push_back(value);
		}
		void						pop(){
			return _cont.pop_back();
		}
	};

	template<class T, class Container>
	bool operator==( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs == rhs);
	}

	template<class T, class Container>
	bool operator!=( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs != rhs);
	}

	template<class T, class Container>
	bool operator<( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs < rhs);
	}

	template<class T, class Container>
	bool operator<=( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs <= rhs);
	}

	template<class T, class Container>
	bool operator>( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs > rhs);
	}

	template<class T, class Container>
	bool operator>=( stack<T, Container>& lhs, stack<T, Container>& rhs ){
		return (lhs >= rhs);
	}
}