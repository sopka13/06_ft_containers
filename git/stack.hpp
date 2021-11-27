/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:53 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/27 23:33:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T>>
	class stack
	{
		ft::vector<T>		_cont;
	public:
		explicit stack( const ft::vector<T>& cont = Container() ) : _cont(cont) {};
		~stack();

		stack<T, ft::vector<T>>&	operator=( const stack<T,Container>& other );
		bool						empty() const{
			return _cont.empty();
		}
		size_t						size() const{
			return _cont.size();
		}
		vector<T>&				top(){
			return _cont.back();
		}
		const ft::vector<T>&		top() const{
			return _cont.back();
		}
		void						push( const T& value ){
			return _cont.push_back();
		}
		void						pop(){
			return _cont.pop_back();
		}
	};

	template<class T, class ctnr = vector<T>>
	bool operator==( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs == rhs);
	}

	template<class T, class ctnr = vector<T>>
	bool operator!=( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs != rhs);
	}

	template<class T, class ctnr = vector<T>>
	bool operator<( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs < rhs);
	}

	template<class T, class ctnr = vector<T>>
	bool operator<=( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs <= rhs);
	}

	template<class T, class ctnr = vector<T>>
	bool operator>( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs > rhs);
	}

	template<class T, class ctnr = vector<T>>
	bool operator>=( stack<T, ctnr>& lhs, stack<T, ctnr>& rhs ){
		return (lhs >= rhs);
	}
}