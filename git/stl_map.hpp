/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_map.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/12/26 15:19:13 by eyohn            ###   ########.fr       */
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
			_parent(parent),
			_k(0)
		{}
		t_treeElem(t_treeElem* parent): // for _n_node
			_parent(parent),
			_k(-1)
		{}
		t_treeElem():					// for _nn_node
			_k(-1)
		{}
		~t_treeElem(){}

		pair<T1, T2>	_kv;
		t_treeElem*		_left;
		t_treeElem*		_right;
		t_treeElem*		_parent;
		int				_k;

	};

	template <class Key, class T, class Compare = less<Key>,
				class Allocator = std::allocator<t_treeElem<const Key, T> > >
	class map
	{
		t_treeElem<const Key, T>*	_tree;
		Compare				_compare;
		Allocator			_al;
		size_t				_size;
		t_treeElem<const Key, T>*	_n_node;
		t_treeElem<const Key, T>*	_nn_node;
		t_treeElem<const Key, T>*	_rn_node;
		t_treeElem<const Key, T>*	_rnn_node;


	public:
		typedef Allocator							allocator_type;
		typedef Compare								key_compare;

		class const_iterator;
		class const_reverse_iterator;

		class iterator {
			t_treeElem<const Key, T>*						_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~iterator() {};

			typedef typename ft::map<Key, T>::iterator&	iterator_type;

			t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			pair<const Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type			operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool					operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type			operator++(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_n_node) {
										_pointer = _map_pointer->_n_node;
									} else {
										_map_pointer->_n_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_n_node, _map_pointer->search_max(_pointer));
										_pointer = _map_pointer->_n_node;
									}
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						if (_map_pointer->_n_node) {
							_pointer = _map_pointer->_n_node;
						} else {
							_map_pointer->_n_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_n_node, _map_pointer->search_max(_pointer));
							_pointer = _map_pointer->_n_node;
						}
					}
				}
				return *this;
			}
			iterator_type			operator--(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_nn_node) {
										_pointer = _map_pointer->_nn_node;
									} else {
										_map_pointer->_nn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_nn_node);
										_pointer = _map_pointer->_nn_node;
									}
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						if (_map_pointer->_nn_node) {
							_pointer = _map_pointer->_nn_node;
						} else {
							_map_pointer->_nn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_nn_node);
							_pointer = _map_pointer->_nn_node;
						}
					}
				}
				return *this;
			}
			bool					operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool					operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool					operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool					operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool					operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			operator const_iterator(){
				return const_iterator(_pointer, _map_pointer);
			}
			
		};

		class const_iterator {
			t_treeElem<const Key, T>*				_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			const_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			const_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			const_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~const_iterator() {};

			typedef typename ft::map<Key, T>::const_iterator&					iterator_type;

			const t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			const pair<Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type					operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool							operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type					operator++(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_n_node) {
										_pointer = _map_pointer->_n_node;
									} else {
										_map_pointer->_n_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_n_node, _map_pointer->search_max(_pointer));
										_pointer = _map_pointer->_n_node;
									}
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						if (_map_pointer->_n_node) {
							_pointer = _map_pointer->_n_node;
						} else {
							_map_pointer->_n_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_n_node, _map_pointer->search_max(_pointer));
							_pointer = _map_pointer->_n_node;
						}
					}
				}
				return *this;
			}
			iterator_type					operator--(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_nn_node) {
										_pointer = _map_pointer->_nn_node;
									} else {
										_map_pointer->_nn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_nn_node);
										_pointer = _map_pointer->_nn_node;
									}
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						if (_map_pointer->_nn_node) {
							_pointer = _map_pointer->_nn_node;
						} else {
							_map_pointer->_nn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_nn_node);
							_pointer = _map_pointer->_nn_node;
						}
					}
				}
				return *this;
			}
			bool							operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool							operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool							operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool							operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool							operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			const pair<const Key, T>*		operator->() {
				return (&_pointer->_kv);
			}
		};
		
		class reverse_iterator {
			t_treeElem<const Key, T>*						_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			reverse_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			reverse_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			reverse_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~reverse_iterator() {};

			typedef typename ft::map<Key, T>::reverse_iterator&	iterator_type;

			t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			pair<const Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type			operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool					operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type			operator--(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_rnn_node) {
										_pointer = _map_pointer->_rnn_node;
									} else {
										_map_pointer->_rnn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_rnn_node);
										_pointer = _map_pointer->_rnn_node;
									}
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						if (_map_pointer->_rnn_node) {
							_pointer = _map_pointer->_rnn_node;
						} else {
							_map_pointer->_rnn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_rnn_node);
							_pointer = _map_pointer->_rnn_node;
						}
					}
				}
				return *this;
			}
			iterator_type			operator++(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_rn_node) {
										_pointer = _map_pointer->_rn_node;
									} else {
										_map_pointer->_rn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_rn_node, _map_pointer->search_min(_pointer));
										_pointer = _map_pointer->_rn_node;
									}
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						if (_map_pointer->_rn_node) {
							_pointer = _map_pointer->_rn_node;
						} else {
							_map_pointer->_rn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_rn_node, _map_pointer->search_min(_pointer));
							_pointer = _map_pointer->_rn_node;
						}
					}
				}
				return *this;
			}
			bool					operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool					operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool					operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool					operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool					operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			operator const_reverse_iterator(){
				return const_reverse_iterator(_pointer, _map_pointer);
			}
			
		};

		class const_reverse_iterator {
			t_treeElem<const Key, T>*						_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			const_reverse_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			const_reverse_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			const_reverse_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~const_reverse_iterator() {};

			typedef typename ft::map<Key, T>::const_reverse_iterator&	iterator_type;

			const t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			const pair<const Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type			operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool					operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type			operator--(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_rnn_node) {
										_pointer = _map_pointer->_rnn_node;
									} else {
										_map_pointer->_rnn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_rnn_node);
										_pointer = _map_pointer->_rnn_node;
									}
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						if (_map_pointer->_rnn_node) {
							_pointer = _map_pointer->_rnn_node;
						} else {
							_map_pointer->_rnn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_rnn_node);
							_pointer = _map_pointer->_rnn_node;
						}
					}
				}
				return *this;
			}
			iterator_type			operator++(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									if (_map_pointer->_rn_node) {
										_pointer = _map_pointer->_rn_node;
									} else {
										_map_pointer->_rn_node = _map_pointer->_al.allocate(1);
										_map_pointer->_al.construct(_map_pointer->_rn_node, _map_pointer->search_min(_pointer));
										_pointer = _map_pointer->_rn_node;
									}
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						if (_map_pointer->_rn_node) {
							_pointer = _map_pointer->_rn_node;
						} else {
							_map_pointer->_rn_node = _map_pointer->_al.allocate(1);
							_map_pointer->_al.construct(_map_pointer->_rn_node, _map_pointer->search_min(_pointer));
							_pointer = _map_pointer->_rn_node;
						}
					}
				}
				return *this;
			}
			bool					operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool					operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool					operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool					operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool					operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			const pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			
		};

		typedef typename ft::map<Key, T>::iterator			iterator_type;
		typedef typename ft::map<Key, T>::const_iterator	const_iterator_type;

		explicit map (const key_compare& comp = Compare(), const allocator_type& alloc = Allocator()):
			_tree(NULL),
			_compare(comp),
			_al(alloc),
			_size(0),
			_n_node(NULL),
			_nn_node(NULL),
			_rn_node(NULL),
			_rnn_node(NULL)
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
			t_treeElem<const Key, T>*		_this = _tree;
			t_treeElem<const Key, T>*		_parent = _tree;
			while (1) {
				if (_parent == NULL)
					break ;
				if (_this->_left == NULL) {
					if (_this->_right == NULL) {
						_parent = _this->_parent;
						_al.destroy(_this);
						_al.deallocate(_this, sizeof(t_treeElem<const Key, T>));
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
			if (_n_node) {
				_al.destroy(_n_node);
				_al.deallocate(_n_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_nn_node) {
				_al.destroy(_nn_node);
				_al.deallocate(_nn_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_rn_node) {
				_al.destroy(_rn_node);
				_al.deallocate(_rn_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_rnn_node) {
				_al.destroy(_rnn_node);
				_al.deallocate(_rnn_node, sizeof(t_treeElem<const Key, T>));
			}
		}

	private:
		t_treeElem<const Key, T>*				search(Key key) {
			// Search Key in tree
			// while (1)
			//		1. if key == node_key
			//			1.1. return true + pointer
			//		2. else if pointer == NULL
			//			2.1. return false + NULL
			//		3. else
			//			3.1. if key < node_key
			//				3.1.1. pointer = left
			//				3.1.2. continue
			//			3.2. else (key > node_key)
			//				3.2.1. pointer = right
			//				3.2.2. continue
			t_treeElem<const Key, T>*		pointer = _tree;
			while (1) {
				if (pointer &&
					key && !_compare(pointer->_kv.first, key) &&
					!_compare(key, pointer->_kv.first))
						return pointer;
				else if (pointer == NULL)
					return NULL;
				else {
					if (_compare(key, pointer->_kv.first)) {
						pointer = pointer->_left;
						continue ;
					} else {
						pointer = pointer->_right;
						continue ;
					}
				}
			}
		}

		void							balance(t_treeElem<const Key, T>* p) {
			//	1. if _k < 0
			//		1.1. go left
			//		1.2. if _k < 0
			//			1.2.1. start left rotate
			//		1.3. else
			//			1.3.1. sart left-right rotate
			//	2. else
			//		2.1. go right
			//		2.2. if _k < 0
			//			2.2.1. start right-left rotate
			//		2.3. else
			//			2.3.1. start right rotate

			t_treeElem<const Key, T>*		temp = NULL;
			if (p->_k < 0){
				temp = p->_left;
				if (temp->_k < 0){
					temp->_parent = p->_parent;
					temp->_right->_parent = p;
					temp->_right = p;
					p->_left = temp->_right;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp;
					else if (p->_parent)
						p->_parent->_right = temp;
					p->_parent = temp;
				} else {
					t_treeElem<const Key, T>*	temp_1 = temp->_right;
					p->_left = temp_1;
					temp->_parent = temp_1;
					temp->_right = temp_1->_left;
					temp_1->_parent = p;
					temp_1->_left->_parent = temp;
					temp_1->_left = temp;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp_1;
					else if (p->_parent)
						p->_parent->_right = temp_1;
					temp_1->_parent = p->_parent;
					p->_parent = temp_1;
					p->_left = temp_1->_right;
					temp_1->_right->_parent = p;
					temp_1->_right = p;
				}
			} else {
				temp = p->_right;
				if (temp->_k < 0){
					if(p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp;
					else if (p->_parent)
						p->_parent->_right = temp;
					temp->_parent = p->_parent;
					p->_parent = temp;
					p->_right = temp->_left;
					temp->_left->_parent = p;
					temp->_left = p;
				} else {
					t_treeElem<const Key, T>*	temp_1 = temp->_left;
					p->_right = temp_1;
					temp->_parent = temp_1;
					temp->_left = temp_1->_right;
					temp_1->_parent = p;
					temp_1->_right->_parent = temp;
					temp_1->_right = temp;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp_1;
					else if (p->_parent)
						p->_parent->_right = temp_1;
					temp_1->_parent = p->_parent;
					p->_parent = temp_1;
					p->_right = temp_1->_left;
					temp_1->_left->_parent = p;
					temp_1->_left = p;
				}
			}
		}

		t_treeElem<const Key, T>*				search_max(t_treeElem<const Key, T>* p) {
			while (1) {
				if (p->_right) {
					p = p->_right;
					continue ;
				} else
					break ;
			}
			return p;
		}

		t_treeElem<const Key, T>*				search_min(t_treeElem<const Key, T>* p) {
			while (1) {
				if (p->_left) {
					p = p->_left;
					continue ;
				} else
					break ;
			}
			return p;
		}

		void							rewrite_k(t_treeElem<const Key, T>* p) {
			while (1) {
				if (p == NULL)
					break ;
				p->_k = ((p->_right ? abs(p->_right->_k) : 0) + 1) -
						((p->_left ? abs(p->_left->_k) : 0) + 1);
				if (abs(p->_k) > 1){
					balance(p);
					continue ;
				} else
					p = p->_parent;
			}
		}

	public:
		// void			insert( const pair<const Key, T>& value ){
		pair<iterator, bool>			insert( const pair<const Key, T>& value ){
			// Search this Key in tree and add if not found
			t_treeElem<const Key, T>*	 pp = search(value.first);
			if (pp) {
				iterator_type it(pp, this);
				pair<iterator_type, bool> ret(it, false);
				return ret;
			}
			// If tree is free
			if (!_size) {
				_tree = _al.allocate(1);				// allocate memory for 1 element
				_al.construct(_tree, value);			// construct element
				rewrite_k(_tree);
				_size++;								// ++ size tree
				iterator_type it(_tree, this);
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
				iterator_type it(_tree, this);
				while (1) {
					if (_compare(value.first, (*(it)).first)) {
						if ((it.get_p())->_left != NULL){
							it = (it.get_p())->_left;
							continue ;
						} else {
							(it.get_p())->_left = _al.allocate(1);					// allocate memory for 1 element
							_al.construct((it.get_p())->_left, value, it.get_p());	// construct element
							rewrite_k((it.get_p())->_left);
							_size++;										// ++ size tree
							iterator_type it2((it.get_p())->_left, this);
							pair<iterator_type, bool> ret(it2, true);
							return ret;
						}
					} else {
						if ((it.get_p())->_right != NULL){
							it = (it.get_p())->_right;
							continue ;
						} else {
							(it.get_p())->_right = _al.allocate(1);					// allocate memory for 1 element
							_al.construct((it.get_p())->_right, value, it.get_p());	// construct element
							rewrite_k((it.get_p())->_right);
							_size++;										// ++ size tree
							iterator_type it2((it.get_p())->_right, this);
							pair<iterator_type, bool> ret(it2, true);
							return ret;
						}
					}
				}
			}
		}

		void							erase( iterator position ){
			// 1. if only one elem in tree
			//		1.1. destructor
			//		1.2. deallocate memory
			//		1.3. size--
			// 2. else
			//		2.1. have child
			//			2.1.1. have left and right
			//				2.1.1.1. compare left _k and right _k
			//				2.1.1.2. search max or min elements
			//				2.1.1.3. have child elemtnts
			//					2.1.1.3.1. rewrite child parent pointer
			//					2.1.1.3.2. rewrite parent child pointer
			//					2.1.1.3.3. rewrite new position pointers (child, parent)
			//					2.1.1.3.4. rewrite _k from parent max/min element
			//					2.1.1.3.5. destructor
			//					2.1.1.3.6. deallocate memory
			//					2.1.1.3.7. size--
			//				2.1.1.4. else
			//					2.1.1.4.1. rewrite parent pointers
			//					2.1.1.4.2. rewrite new position pointers (child, parent)
			//					2.1.1.4.3. rewrite _k from parent max/min element
			//					2.1.1.4.4. destructor
			//					2.1.1.4.5. deallocate memory
			//					2.1.1.4.6. size--
			//			2.1.2. have left or right only
			//				2.1.2.1. rewrite child parent pointer
			//				2.1.2.2. rewrite parent child pointer
			//				2.1.2.3. rewrite _k from parent
			//				2.1.2.4. destructor
			//				2.1.2.5. deallocate memory
			//				2.1.2.6. size--
			//		2.2. don't have child
			//			2.2.1. rewrite parent pointer
			//			2.2.2. rewrite _k and rebalanse
			//			2.2.3. destructor
			//			2.2.4. deallocate memory
			//			2.2.5. size--

			if (_size == 1) {
				_al.destroy(position.get_p());
				_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
				_size--;
				return ;
			} else {
				t_treeElem<const Key, T>*		left = NULL;
				t_treeElem<const Key, T>*		right = NULL;
				t_treeElem<const Key, T>*		parent = NULL;
				t_treeElem<const Key, T>*		new_this = NULL;
				t_treeElem<const Key, T>*		temp = NULL;
				if ((position.get_p())->_left || (position.get_p())->_right){
					if ((position.get_p())->_left && (position.get_p())->_right){
						int l = 0;
						int r = 0;
						if (abs((position.get_p())->_left->_k) >= abs((position.get_p())->_right->_k)){
							new_this = search_max((position.get_p())->_left);
							l++;
						} else {
							new_this = search_min((position.get_p())->_right);
							r++;
						}
						if (new_this->_left || new_this->_right){
							if (l){
								new_this->_parent->_right = new_this->_left;
								new_this->_left->_parent = new_this->_parent;
							} else {
								new_this->_parent->_left = new_this->_right;
								new_this->_right = new_this->_parent;
							}
						} else {
							if (new_this->_parent->_left == new_this)
								new_this->_parent->_left = NULL;
							else
								new_this->_parent->_right = NULL;
						}
						temp = new_this->_parent;
						left = (position.get_p())->_left;
						right = (position.get_p())->_right;
						parent = (position.get_p())->_parent;
						new_this->_parent = parent;
						if (parent && parent->_left == (position.get_p()))
							parent->_left = new_this;
						else if (parent && parent->_right == (position.get_p()))
							parent->_right = new_this;
						new_this->_left = left;
						if (left)
							left->_parent = new_this;
						new_this->_right = right;
						if (right)
							right->_parent = new_this;
						rewrite_k(temp);
						_al.destroy(position.get_p());
						_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
						_size--;
						return ;
					} else if ((position.get_p())->_left) {
						if ((position.get_p())->_parent->_left == position.get_p())
							(position.get_p())->_parent->_left = (position.get_p())->_left;
						else
							(position.get_p())->_parent->_right = (position.get_p())->_left;
					} else {
						if ((position.get_p())->_parent->_left == position.get_p())
							(position.get_p())->_parent->_left = (position.get_p())->_right;
						else
							(position.get_p())->_parent->_right = (position.get_p())->_right;
					}
				} else {
					if ((position.get_p())->_parent->_left == position.get_p())
						(position.get_p())->_parent->_left = NULL;
					else
						(position.get_p())->_parent->_right = NULL;
					rewrite_k(position.get_p());
					_al.destroy(position.get_p());
					_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
					_size--;
					return ;
				}
			}

			// t_treeElem<const Key, T>*		left = NULL;
			// t_treeElem<const Key, T>*		right = NULL;
			// t_treeElem<const Key, T>*		parent = NULL;
			// if (position.get_p()->left)
			// 	left = position.get_p()->left;
			// if (position.get_p()->right)
			// 	right = position.get_p()->right;
			// if (position.get_p()->parent)
			// 	parent = position.get_p()->parent;
			// // 3. rewrite parent address
			// if (parent){
			// 	// 3.1. Check have parent
			// 	// 3.2. Check have left and right
			// 	if (left && right){								// if left and right != NULL
			// 		// 3.2.1. get _k from _left and _right
			// 		// 3.2.2. select an item for replace
			// 		if (abs(left->_k) >= abs(right->_k)){			// left k >= right k
			// 			if (parent->_left == position.get_p()){			// if left tree
			// 				// search max elem
			// 				t_treeElem<const Key, T>*		new_this = search_max(position);
			// 				// rewrite max elem parent pointer
			// 				if (new_this->_left){
			// 					new_this->_parent->_right = new_this->_left;
			// 				} else
			// 					new_this->_parent->_right = NULL;
			// 				t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 				// install max elem in current position
			// 				new_this->_parent = parent;
			// 				if (parent->_left == position.get_p())
			// 					parent->_left = new_this;
			// 				else
			// 					parent->_right = new_this;
			// 				new_this->_left = left;
			// 				left->_parent = new_this;
			// 				new_this->_right = right;
			// 				right->_parent = new_this;
			// 				// rewrite _k
			// 				rewrite_k(temp);
			// 			} else {										// if right tree
			// 				// search min elem
			// 				t_treeElem<const Key, T>*		new_this = search_min(position);
			// 				// rewrite min elem parent pointer
			// 				if (new_this->_right){
			// 					new_this->_parent->_left = new_this->_right;
			// 				} else
			// 					new_this->_parent->_left = NULL;
			// 				t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 				// install min elem in current position
			// 				new_this->_parent = parent;
			// 				if (parent->_left == position.get_p())
			// 					parent->_left = new_this;
			// 				else
			// 					parent->_right = new_this;
			// 				new_this->_left = left;
			// 				left->_parent = new_this;
			// 				new_this->_right = right;
			// 				right->_parent = new_this;
			// 				// rewrite _k
			// 				rewrite_k(temp);
			// 			}
			// 		} else {										// right k > left k
			// 			if (parent->_left == position.get_p()){			// if left tree
			// 				// search max elem
			// 				t_treeElem<const Key, T>*		new_this = search_max(position);
			// 				// rewrite max elem parent pointer
			// 				if (new_this->_left){
			// 					new_this->_parent->_right = new_this->_left;
			// 				} else
			// 					new_this->_parent->_right = NULL;
			// 				t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 				// install max elem in current position
			// 				new_this->_parent = parent;
			// 				if (parent->_left == position.get_p())
			// 					parent->_left = new_this;
			// 				else
			// 					parent->_right = new_this;
			// 				new_this->_left = left;
			// 				left->_parent = new_this;
			// 				new_this->_right = right;
			// 				right->_parent = new_this;
			// 				// rewrite _k
			// 				rewrite_k(temp);
			// 			} else {										// if right tree
			// 				// search min elem
			// 				t_treeElem<const Key, T>*		new_this = search_min(position);
			// 				// rewrite min elem parent pointer
			// 				if (new_this->_right){
			// 					new_this->_parent->_left = new_this->_right;
			// 				} else
			// 					new_this->_parent->_left = NULL;
			// 				t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 				// install min elem in current position
			// 				new_this->_parent = parent;
			// 				if (parent->_left == position.get_p())
			// 					parent->_left = new_this;
			// 				else
			// 					parent->_right = new_this;
			// 				new_this->_left = left;
			// 				left->_parent = new_this;
			// 				new_this->_right = right;
			// 				right->_parent = new_this;
			// 				// rewrite _k
			// 				rewrite_k(temp);
			// 			}
			// 		}
			// 	} else if (left){								// if right == NULL
			// 		// 3.2.2.
			// 		// search max elem
			// 		t_treeElem<const Key, T>*		new_this = search_max(position);
			// 		// rewrite max elem parent pointer
			// 		if (new_this->_left){
			// 			new_this->_parent->_right = new_this->_left;
			// 		} else
			// 			new_this->_parent->_right = NULL;
			// 		t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 		// install max elem in current position
			// 		new_this->_parent = parent;
			// 		if (parent->_left == position.get_p())
			// 			parent->_left = new_this;
			// 		else
			// 			parent->_right = new_this;
			// 		new_this->_left = left;
			// 		left->_parent = new_this;
			// 		new_this->_right = right;
			// 		right->_parent = new_this;
			// 		// rewrite _k
			// 		rewrite_k(temp);
			// 	} else if (right) {								// if left == NULL
			// 		// 3.2.3.
			// 		// search min elem
			// 		t_treeElem<const Key, T>*		new_this = search_min(position);
			// 		// rewrite min elem parent pointer
			// 		if (new_this->_right){
			// 			new_this->_parent->_left = new_this->_right;
			// 		} else
			// 			new_this->_parent->_left = NULL;
			// 		t_treeElem<const Key, T>*		temp = new_this->_parent;
			// 		// install min elem in current position
			// 		new_this->_parent = parent;
			// 		if (parent->_left == position.get_p())
			// 			parent->_left = new_this;
			// 		else
			// 			parent->_right = new_this;
			// 		new_this->_left = left;
			// 		left->_parent = new_this;
			// 		new_this->_right = right;
			// 		right->_parent = new_this;
			// 		// rewrite _k
			// 		rewrite_k(temp);
			// 	} else {										// if left and right == NULL
			// 		// 3.2.4.1. parent._left or _right = NULL
			// 		// 3.2.4.2. parent _k += -1
			// 		if (parent->_left == position.get_p()){
			// 			parent->_left = NULL;
			// 			parent->_k += 1
			// 		}
			// 		else {
			// 			parent->_right = NULL;
			// 			parent->_k += -1
			// 		}
			// 	}
			// }
			// // 4. rewrite left elem address
			// // 5. rewrite right elem address
			// // 6. check balance
			// // 7. rewrite _size
			// // 8. rewrite iterator position
			// // Search for the item you want and take it from tree
			// t_treeElem<const Key, T>* new_this;
			// if (abs(left->_k) >= abs(right->_k)){		// this is left tree
			// 	new_this = search_max(position.get_p());
			// 	if (new_this->_left)
			// 		new_this->_parent->_right = new_this->_left;
			// 	else
			// 		new_this->_parent->_right = NULL;
			// } else {									// this is rigth tree
			// 	new_this = search_min(position.get_p());
			// 	if (new_this->_right)
			// 		new_this->_parent->_left = new_this->_right;
			// 	else
			// 		new_this->_parent->_left = NULL;
			// }
			// // Change elements
			// t_treeElem<const Key, T>*		temp = new_this->_parent;
			// new_this->_parent = parent;
			// if (parent->_left == position.get_p())
			// 	parent->_left = new_this;
			// else
			// 	parent->_right = new_this;
			// new_this->_left = left;
			// left->_parent = new_this;
			// new_this->_right = right;
			// right->_parent = new_this;
			// // Rewrite _k and rebalanse
			// rewrite_k(temp);
			// // 1. Start destructor
			// _al.destroy(position.get_p());
			// // 2. Start deallocate
			// _al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
			// _size--;
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
			return static_cast<size_t>(c / sizeof(t_treeElem<const Key, T>));
		}

		// Iterators:
		iterator				begin(){
			return iterator(search_min(_tree), this);
		}
		const_iterator			begin() const {
			return const_iterator(search_min(_tree), this);
		}
		iterator				end(){
			if (_n_node) {
				return iterator(_n_node, this);
			} else {
				_n_node = _al.allocate(1);
				_al.construct(_n_node, search_max(_tree));
				return iterator(_n_node, this);
			}
		}
		const_iterator			end() const {
			if (_n_node) {
				return const_iterator(_n_node, this);
			} else {
				_n_node = _al.allocate(1);
				_al.construct(_n_node, search_max(_tree));
				return const_iterator(_n_node, this);
			}
		}
		reverse_iterator		rbegin(){
			return reverse_iterator(search_max(_tree), this);
		}
		const_reverse_iterator	rbegin() const{
			return const_reverse_iterator(search_max(_tree), this);
		}
		reverse_iterator		rend(){
			if (_rn_node) {
				return reverse_iterator(_rn_node, this);
			} else {
				_rn_node = _al.allocate(1);
				_al.construct(_rn_node, search_min(_tree));
				return reverse_iterator(_rn_node, this);
			}
		}
		const_reverse_iterator	rend() const{
			if (_rnn_node) {
				return const_reverse_iterator(_rnn_node, this);
			} else {
				_rnn_node = _al.allocate(1);
				_al.construct(_rnn_node, search_min(_tree));
				return const_reverse_iterator(_rnn_node, this);
			}
		}
	};
}