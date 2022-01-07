/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:53 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/07 10:48:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container		container_type;

	protected:
		container_type		c;
	public:
		explicit stack( const container_type& cont = container_type() ) : c(cont) {}
		stack(const stack& other) : c(other.c) {}
		// ~stack();


		stack&						operator=( const stack& other ){
			c = other.c;
			return *this;
		}
		bool						empty() const{
			return c.empty();
		}
		size_t						size() const{
			return c.size();
		}
		T&							top(){
			return c.back();
		}
		const T&					top() const{
			return c.back();
		}
		void						push( const T& value ){
			return c.push_back(value);
		}
		void						pop(){
			return c.pop_back();
		}
	};

	template<class T, class Container>
	bool operator==( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs == rhs);
	}

	template<class T, class Container>
	bool operator!=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs != rhs);
	}

	template<class T, class Container>
	bool operator<( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs < rhs);
	}

	template<class T, class Container>
	bool operator<=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs <= rhs);
	}

	template<class T, class Container>
	bool operator>( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs > rhs);
	}

	template<class T, class Container>
	bool operator>=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs >= rhs);
	}

	// template<class T, class Container = ft::vector<T> >
	// class stack{

	// public:
	// typedef T value_type;
	// typedef Container container_type;
	// typedef typename Container::size_type size_type;
	// typedef value_type& reference;
	// typedef const value_type& const_reference;

	// protected:
	// 	container_type _container;
	
	// public:	
	
	// explicit stack (const container_type& cont = container_type()) : _container(cont){}
	
	// stack(const stack& other): _container(other._container) {}

	// stack& operator=(const stack& other){
	// 	_container = other._container;
	// 	return (*this);
	// }

	// bool empty() const{
	// 	return (_container.empty());
	// }

	// size_type size() const{
	// 	return (_container.size());
	// }

	// value_type& top(){
	// 	return (_container.back());
	// }

	// const value_type& top() const{
	// 	return (_container.back());
	// }

	// void push (const value_type& val){
	// 	_container.push_back(val);
	// }

	// void pop(){
	// 	_container.pop_back();
	// }



	// template <class A, class Cont>
	// 	  friend bool operator== (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container == rhs._container);
	// 		 }
	// template <class A, class Cont>
	// 	  friend bool operator!= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container != rhs._container);
	// 		 }
	// template <class A, class Cont>
	// 	  friend bool operator<  (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container < rhs._container);
	// 		 }
	// template <class A, class Cont>
	// 	  friend bool operator<= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container <= rhs._container);
	// 	  }
	// template <class A, class Cont>
	// 	  friend bool operator>  (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container > rhs._container);
	// 	  }
	// template <class A, class Cont>
	// 	  friend bool operator>= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
	// 			return(lhs._container >= rhs._container);
	// 		}

// };
}