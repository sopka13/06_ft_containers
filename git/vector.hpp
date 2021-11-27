/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/27 22:52:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "source.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		T*			_container;
		size_t		_size;
		Allocator	_alloc;
		size_t		_capacity;

	public:
		explicit vector( const Allocator& alloc = Allocator() );
		explicit vector( size_t count, const T& value = T(), const Allocator& alloc = Allocator());
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		vector( const vector& other);
		~vector();

		vector& operator=(const vector& other);

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
		size_t				size() const{
			return (_size);
		}
		size_t				max_size() const{
			return (_alloc.max_alloc());
		}
		// void				reserve( size_t size ){
		// 	if (size <= _capacity)
		// 		return ;
		// 	int n = ft::max(_capacity, size);
		// 	T* temp = new T[n];
		// 	for (size_t k = 0; k < _size; ++k)
		// 		temp[k] = _container[k];
		// 	delete[] _container;
		// 	_container = temp;
		// 	_capacity = n;
		// }
		size_t				capacity() const{
			return (_capacity);
		}
		bool				empty() const{
			if (_size)
				return (false);
			return (true);
		}

		// Element access:
		T&					operator[]( size_t pos ){
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		const T&			operator[]( size_t pos ) const{
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		T&					at( size_t pos ){
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		const T&			at( size_t pos ) const{
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		T&		 			front(){
			return (_container[0]);
		}
		const T&			front() const{
			return (_container[0]);
		}
		T&		 			back(){
			return (_container[_size - 1]);
		}
		const T&			back() const{
			return (_container[_size - 1]);
		}
		T*					data(){
			return (&_container[0]);
		}
		const T*			data() const{
			return (&_container[0]);
		}

		// Modifiers:
		void				assign( size_t count, const T& value ){
			this->clear();
			for (size_t k = 0; k < count; ++k)
				push_back(value);
		}
		template< class InputIt >
		void				assign( InputIt first, InputIt last ){
			this->clear();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		// void				push_back( const T& value ){
		// 	if (!_size)
		// 		reserve(1);
		// 	else
		// 		reserve(_size + 1);
		// }
		void				pop_back(){
			_size--;
		}
		// iterator			insert( iterator pos, const T& value ){
		// 	size_t n = ft::distance(begin(), pos);
		// 	insert(pos, 1, value);
		// 	return (iterator(&(_container[n])));
		// }
		// void				insert( iterator pos, size_t count, const T& value ){
		// 	vector temp(pos, end());
		// 	_size -= ft::distance(pos, end());
		// 	while (count){
		// 		push_back(value)
		// 		--count;
		// 	}
		// 	vector<T>::iterator it = temp.begin();
		// 	while (it != temp.end()){
		// 		push_back(*it);
		// 		it++;
		// 	}
		// }
		// template< class InputIt >
		// void				insert( iterator pos, InputIt first, InputIt last){
		// 	vector temp(pos, end());
		// 	_size -= ft::distance(pos, end());
		// 	while (first != last){
		// 		push_back(*first);
		// 		first++;
		// 	}
		// 	vector<T>::iterator it = temp.begin();
		// 	while (it != temp.end()){
		// 		push_back(*it);
		// 		it++;
		// 	}
		// }
		// iterator			erase( iterator pos ){
		// 	iterator ret(pos);
		// 	while (pos != end() - 1) {
		// 		*pos = *(pos + 1);
		// 		pos++;
		// 	}
		// 	_size--;
		// 	return (ret);
		// }
		// iterator			erase( iterator first, iterator last ){
		// 	iterator ret(last);
		// 	while (last != end()){
		// 		*first = *last;
		// 		first++;
		// 		last++;
		// 	}
		// 	_size -= ft::distance(first, last);
		// 	return (ret);
		// }
		void				swap( vector& other ){
			vector temp(other);
			other = *this;
			*this = temp;
		}
		void				clear(){
			while (_size)
				pop_back();
		}
		// void				resize( size_t count, T value = T() ){
		// 	while (count < _size)
		// 		pop_back();
		// 	if (count > _capacity)
		// 		reserve(count);
		// 	while (count > _size)
		// 		push_back(value);
		// }

		// Allocator:
		Allocator			get_allocator() const{
			return (_alloc);
		}
	};

	template<class T>
	bool operator==( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (true);
		if (lhs.size() != rhs.size())
			return (false);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs != *start_rhs)
				return (false);
			start_lhs++;
			start_rhs++;
		}
		return (true);
	}

	template<class T>
	bool operator!=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() != rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs != *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator<( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() < rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs < *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator<=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (true);
		if (lhs.size() <= rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs <= *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator>( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() > rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs > *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator>=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() >= rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs >= *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}
}