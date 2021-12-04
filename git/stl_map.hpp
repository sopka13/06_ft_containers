/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_map.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/04 17:55:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unistd.h>
#include "source.hpp"

namespace ft {
	template<typename T1, typename T2>
	class t_treeElem {

	public:
		t_treeElem(const pair<const T1, T2>& value, t_treeElem* parent = NULL):
			_kv(value.first, value.second),
			_left(NULL),
			_right(NULL),
			_parent(parent)
		{
		}
		~t_treeElem(){}

		pair<T1, T2>	_kv;
		t_treeElem*		_left;
		t_treeElem*		_right;
		t_treeElem*		_parent;

	};

	template <class Key, class T, class Compare = less<Key>,
				class Allocator = std::allocator<t_treeElem<Key, T> > >
	class map
	{
		t_treeElem<Key, T>*	_tree;
		Compare				_compare;
		Allocator			_al;
		size_t				_size;

	public:
		typedef Allocator							allocator_type;
		typedef Compare								key_compare;
		
		class iterator {
			t_treeElem<Key, T>*	_pointer;

		public:
			iterator():
				_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			iterator(t_treeElem<Key, T>* pointer):
				_pointer(pointer)
			{}
			~iterator() {};

			t_treeElem<Key, T>*			get_p() {
				return (_pointer);
			}
			pair<Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			// ft::map<Key, T>::iterator	operator=(t_treeElem<Key, T>* pointer) {
			// 	return (iterator(pointer));
			// }
			t_treeElem<Key, T>*			operator->() {
				return (_pointer);
			}
		};
		
		typedef typename ft::map<Key, T>::iterator	iterator_type;

		explicit map (const key_compare& comp = Compare(), const allocator_type& alloc = Allocator()):
			_tree(NULL),
			_compare(comp),
			_al(alloc),
			_size(0)
		{}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());

		// map (const map& x);

		~map(){
			//	1. if left == null
			//		1.1 if right == null
			//			1.1.1. free
			//			1.1.2. go parent
			//		1.2 else
			//			1.2.1. go right
			//	2. else
			//		2.1. go left
			std::cout << "Destructor map start" << std::endl;
			t_treeElem<Key, T>*		_this = _tree;
			t_treeElem<Key, T>*		_parent = _tree;
			while (1) {
				if (_parent == NULL)
					return ;
				if (_this->_left == NULL) {
					if (_this->_right == NULL) {
						_parent = _this->_parent;
						_al.destroy(_this);
						_al.deallocate(_this, sizeof(t_treeElem<Key, T>));
						_this = _parent;
						if (_this && !_this->_left)
							_this->_right = NULL;
						else if (_this)
							_this->_left = NULL;
						continue;
					} else {
						_parent = _this;
						_this = _this->_right;
						continue;
					}
				} else {
					_parent = _this;
					_this = _this->_left;
					continue ;
				}
			}
		}

		// void			insert( const pair<const Key, T>& value ){
		pair<iterator, bool>			insert( const pair<const Key, T>& value ){
			if (!_size) {
				// If tree is free
				_tree = _al.allocate(1);				// allocate memory for 1 element
				_al.construct(_tree, value);			// construct element
				_size++;								// ++ size tree
				iterator_type it(_tree);
				pair<iterator_type, bool> ret(it, true);
				return ret;
			} else {
				// If tree is non free
				// 1. Check compare iterator and key insert element
				// 2. If true
				//		2.1. Check for left elem
				//		2.2. If have
				//			2.2.1. Change iterator
				//			2.2.2. Continue
				//		2.3. Else
				//			2.3.1. Allocate memory
				//			2.3.2. Construct elem
				//			2.3.3. Add size
				// 3. else
				//		3.1. Check for left elem
				//		3.2. If have
				//			3.2.1. Change iterator
				//			3.2.2. Continue
				//		3.3. Else
				//			3.3.1. Allocate memory
				//			3.3.2. Construct elem
				//			3.3.3. Add size
				iterator_type it = _tree;
				while (1) {
					if (_compare(value.first, (*(it)).first)) {
						if (it->_left != NULL){
							it = it->_left;
							continue ;
						} else {
							it->_left = _al.allocate(1);					// allocate memory for 1 element
							_al.construct(it->_left, value, it.get_p());		// construct element
							_size++;										// ++ size tree
							iterator_type it2(it->_left);
							pair<iterator_type, bool> ret(it2, true);
							return ret;
						}
					} else {
						if (it->_right != NULL){
							it = it->_right;
							continue ;
						} else {
							it->_right = _al.allocate(1);					// allocate memory for 1 element
							_al.construct(it->_right, value, it.get_p());		// construct element
							_size++;										// ++ size tree
							iterator_type it2(it->_right);
							pair<iterator_type, bool> ret(it2, true);
							return ret;
						}
					}
				}
			}
		}

		void less() {
			std::cout << _compare(_tree->_key, _tree->_value) << std::endl;
		}

		// Capacity:
		bool				empty() const {
			return (_size) ? false : true;
		}
		size_t				size() const {
			return _size;
		}
		size_t				max_size() const {
			long a = sysconf(_SC_PHYS_PAGES);
			long b = sysconf(_SC_PAGESIZE);
			long c = a * b;
			return static_cast<size_t>(c / sizeof(t_treeElem<Key, T>));
		}
	};
}