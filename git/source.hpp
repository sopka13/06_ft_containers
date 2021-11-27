/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:50:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/27 23:39:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	In this class i want get iterator and all method
*/

#pragma once

class iterator{
	
public:

};

class iterator_trails{

public:

};

class reverse_iterator{

public:

};

class enable_if{

public:

};

class is_integral{

public:

};

class equal{

public:

};

class Lexicographical_compare{

public:

};

template<class _T1, class _T2>
struct pair {
	// typedef _T1 first_type;
	// typedef _T2 second_type;
	_T1 first;
	_T2 second;

	pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
	{ return pair<_T1, _T2>(__x, __y); }
};
template<typename _T1, typename _T2>
bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return __x.first == __y.first && __x.second == __y.second; }
template<typename _T1, typename _T2>
bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__x == __y); }
template<typename _T1, typename _T2>
bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return __x.first < __y.first
		|| (!(__y.first < __x.first) && __x.second < __y.second); }
template<typename _T1, typename _T2>
bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__y < __x); }
template<typename _T1, typename _T2>
bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return __y < __x; }
template<typename _T1, typename _T2>
bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__x < __y); }

template <class Arg1, class Arg2, class Result>
struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
};

template <class T> struct less : binary_function <T,T,bool> {
	bool operator() (const T& x, const T& y) const {
		return x<y;
	}
};