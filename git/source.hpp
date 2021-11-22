/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:50:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/16 01:36:18 by eyohn            ###   ########.fr       */
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

template<class T1, class T2>
class pair {

public:

};

class make_pair {

public:

};

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