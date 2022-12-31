#pragma once


#include <memory>
#include <iostream>
#include <iterator>
#include "../Integral.hpp"
#include "../Equal.hpp"
#include "../Pair.hpp"
#include "../ReverseIterator.hpp"
#include "../IteratorTraits.hpp"
#include "MapIterator.hpp"
#include "ReverseMapIterator.hpp"
#include <algorithm>
#include <unistd.h>
namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > > 
	class map {

		private:
			struct  Node {
				pair<const Key, T>				content;
				Node*                           parent;
				Node*							left;
				Node*							right;
				Node*							last;
				long long int                   level;
				bool							isLast;
			};
		
			struct constNode {
				const pair<const Key, T>				content;
				constNode*                           parent;
				constNode*							left;
				constNode*							right;
				constNode*							last;
				long long int                   level;
				bool							isLast;
			};

		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef std::size_t					size_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef T&							reference;
			typedef const T&					const_reference;
			typedef T*							pointer;
			typedef const T*					const_pointer;



		public:

			typedef typename ft::MapIterator<value_type, Compare, Node>							iterator;
			typedef typename ft::MapIterator<const value_type, Compare, constNode>					const_iterator;
			typedef	typename ft::ReverseMapIterator<value_type, Compare, Node>											reverse_iterator;
			typedef	typename ft::ReverseMapIterator<const value_type, Compare, constNode>									const_reverse_iterator;

			class value_compare {
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef	bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					};
			};

			key_compare key_comp() const { return (key_compare());}

			value_compare value_comp() const { return (value_compare(key_compare()));}



		private:
			allocator_type						_malloc;
			std::allocator<Node>				_mallocNode;
			Node*								_root;
			Node*								_last;
			size_type							_size;
			key_compare							_comp;


		public:

			map (const map& x) :  _malloc(x._malloc), _mallocNode(x._mallocNode), _size(0), _comp(x._comp){
				_root = NULL;
				_last = _mallocNode.allocate(1);
				_malloc.construct(&x._last->content, value_type());
				for (iterator it = x.begin(); it != x.end(); ++it)
                	insert(it.getNodePtr()->content);
			};

			explicit map( const key_compare& comp = key_compare(), const Allocator& alloc = Allocator())
				: _malloc(alloc), _root(NULL), _last(_mallocNode.allocate(1)), _size(0),  _comp(comp){
					_malloc.construct(&_last->content, value_type());
				};

			template<class InputIt>
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _mallocNode(alloc), _size(0), _comp(comp){
					_root = NULL;
					_last = _mallocNode.allocate(1);
					_malloc.construct(&_last->content, value_type());
               	 	for (; first != last; ++first)
                    		insert(first.getNodePtr()->content);
			};

			~map(){
				if (_root && _root != _last){
					_root = find_root(_root);
					__full_clear(_root);
				}
				if (_last){
					_malloc.destroy(&_last->content);
					_malloc.deallocate(&_last->content, 1);
				}
			};

			allocator_type get_allocator() const { return _malloc;};

			Node* find_min(Node* node) const {
				if (!node)
					return (NULL);
				else if (!node->left)
					return (node);
				else
				    return find_min(node->left);
			}

			constNode* find_miin(Node* node) const {
				if (!node)
					return (NULL);
				else if (!node->left)
					return ((constNode*)node);
				else
				    return find_miin(node->left);
			}

			Node* find_root(Node* node) const {
				while (node->parent)
					node = node->parent;
				return node;
			}
			
			Node* find_max(Node* node) const {
				if (!node)
					return (NULL);
				else if (!node->right)
					return (node);
				else
					return find_max(node->right);
			}

			bool empty() const {
				
				if (!_size)
					return true;
				return
					false;
			};

			size_type size() const {return _size;};

			size_type max_size() const {return allocator_type().max_size();};

			iterator begin(){  return iterator(find_min(_root), _comp);}

			const_iterator begin() const { return const_iterator(find_miin(_root), _comp);}

			reverse_iterator rbegin(){return reverse_iterator(_last->parent, _comp);};

			const_reverse_iterator rbegin() const {return const_reverse_iterator((constNode*)_last->parent, _comp);};

    		reverse_iterator rend(){
				Node* tmp = find_min(_root);
				tmp->right = NULL;
				return reverse_iterator(tmp->right, _comp);};

			const_reverse_iterator rend() const{
				Node* tmp = find_min(_root);
				tmp->right = NULL;
				return const_reverse_iterator((constNode*)tmp->right, _comp);};


			iterator end() { return iterator(_last, _comp);}

			const_iterator end() const { return const_iterator((constNode*)_last, _comp);}

			Node* getRoot(){return _root;}

			Node *search_key(Node *node, const key_type &k) const{
				while (node){
					if (node->content.first == k)
						return (node);
					if (node->content.first < k)
						node = node->right;
					else if (node->content.first > k)
						node = node->left;
				}
				
				return (NULL);
			}

			iterator find (const key_type& k){
				Node *res = search_key(_root, k);
				if (!res)
					return this->end();
				//std::cout << res->content.first << std::endl;
				return (iterator(res));
			};
			
			const_iterator find (const key_type& k) const {
				Node *res = search_key(_root, k);
				// if (!res)
				// 	return this->end();
				return (const_iterator(res));
			};


			size_type count (const key_type& k) const{
				Node *search = search_key(_root, k);
				return (search ? true : false);
			};

			map& operator= (const map& x) {
				if (&x == this)
					return (*this);
				
				clear();
				if (!x.empty()){
					insert(x.begin(), x.end());
					_size = x._size;
				}

				return(*this);
			}

			mapped_type& operator[] (const key_type& k){
			//	std::cout << "ici\n";
				if (!count(k)){
					value_type val(k, mapped_type());
					insert(val);
				}
				Node*	node = search_key(_root, k);
				return (node->content.second);
			};

// INSERT
			ft::pair<iterator, bool> insert( const value_type& value ){
			//	std::cout << "gsdtgsdf\n";
				if (count(value.first))  // a verifier
					return ft::make_pair<iterator, bool>(iterator(search_key(_root, value.first), _comp), false);
			//	_root = find_root(_root);
				_root = insertInTree(_root, value, NULL);
				//_last->left = find_max(_root);
				_last->parent = find_max(_root);
				_last->last = NULL;
				_last->right = NULL;
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(_root, _comp), true));
			};

			iterator insert (iterator position, const value_type& val){
				//std::cout << position->first << std::endl;
				iterator it(_root = insertInTree(_root, val, NULL));
				position = it;
				_size++;
				return (position);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last,
		    typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0){
				while(first != last){
					insert(first.getNodePtr()->content);
					++first;
				}
			};

// ERASE
			void erase (iterator position){
				Node *test = position.getNodePtr();
				if (_size > 1)
					_root = find_root(_last);
				_root = remove(test->content.first, _root);		
				if (_size > 1)
					_root = find_root(_last);
				--_size;
			};

			size_type erase (const key_type& k){
				if (!count(k))
					return 0;
				Node* res = remove(k, _root);
				if (!res)
					return 0;
				_size--;
				return 1;
			};

    		void erase (iterator first, iterator last){
				int i = 0;
				bool boool = false;
				for (iterator it = first; it != last;){
					i++;
					it++;
				};
					if (last == end()){
						boool = true;
					}
				int j = 0;
				
				iterator it(first);
				for (; j < i;){	
					Node *test = first.getNodePtr();
				
				//	iterator it = first;
					// if (it == last && last == end()){
					// 	i += 1;
					// }
					if (boool)
						++it;
					// if (it == end())
					// {
					// 	return;
					// }
					
					if (_size > 2)
						_root = find_root(_last);
					_root = remove(test->content.first, _root);		
					_size--;
					if (_size > 2)
						_root = find_root(_last);
					// if (last == end()){
					// 	i   -= 1;
					// }
					j++;
						first = it;
				}

				
					// if (last == end()){
					// 	_last->parent = find_max(_root);
					// 	_last->left = find_max(_root);
					// }




				// for (iterator it = first; it != last;){
				// 	iterator tmp(it);
				// 	Node test = *it.getNodePtr();
				// 	if (_size > 2)
				// 		_root = find_root(_last);
				// 	_root = remove(test.content.first, _root);		
				// 	--_size;
				// 	if (_size > 2)
				// 		_root = find_root(_last);


				// 	//tmp++;
				// 	std::cout << "tmmmmmmmp = " << test.content.first << "\n";
				// 	std::cout << "tmp = " << tmp->first << "\n";
				// 	//_root = find_root(_last);
				// 	if (!last)
				// 		return;
				// 	it = tmp;
			
				// }
				
			};

// UTILS

			long long int _height(Node* temp){
        		return (temp == NULL ? -1 : temp->level);
			}

			int diff(Node *temp)
			{
				int l_height = _height(temp->left);
				int r_height = _height(temp->right);
				int b_factor = l_height - r_height;
				return b_factor;
			}

// delete
			//node start as root
			Node* remove(const key_type& content, Node* node)
    		{
    			Node* temp;

    		    if(node == NULL)
    		        return NULL;
    		    else if(content < node->content.first)
    		        node->left = remove(content, node->left);
    		    else if(content > node->content.first)
    		        node->right = remove(content, node->right);
    		    else if(node->left && node->right)
    		    {
					Node* parent;
					if (node->parent){
						parent = node->parent;
					}
					// if (node == _root)
					// 	_root = NULL;
    		        temp = find_min(node->right);
					_malloc.destroy(&node->content);
					//_malloc.deallocate(&node->content, 1);
					//std::cout << _size << "\n";
					
					_malloc.construct(&node->content, temp->content);
					if (node->parent)
						node->parent = parent;
					//	std::cout << "ici\n";
					node->right = remove(node->content.first, node->right);
					// if (!_root)
					// 	_root = find_root(node);
				}
    		    else
    		    {
					//if  (node == find_max)
    		        temp = node;
					if (node->parent && node->parent->content > node->content)
						node->parent->left = NULL;
					if (node->parent && node->parent->content < node->content)
						node->parent->right = NULL;
    		        if(node->left == NULL){
						if (node->right)
							node->right->parent = node->parent;
    		            node = node->right;
					}
    		        else if(node->right == NULL){
						if (node->left)
							node->left->parent = node->parent;
    		            node = node->left;
					}
    		        _malloc.destroy(&temp->content);
					_malloc.deallocate(&temp->content, 1);
					_mallocNode.destroy(temp);

    		    }
    		    if(node == NULL){
					if (_size == 1){
						_root = NULL;
						return _last;
					}
    		        return node;
				}
    		    node->level = std::max(_height(node->left), _height(node->right))+1;
    		    if(_height(node->left) - _height(node->right) == 2)
    		    {
    		        if(_height(node->left->left) - _height(node->left->right) == 1){
						Node* tmp;
						tmp = __SLRotate(node);
						_root = find_root(tmp);
    		            return tmp;
					}
    		        else{
						Node* tmp;
						tmp = __DLRotate(node);
						_root = find_root(tmp);
    		            return tmp;
					}
    		    }
    		    else if(_height(node->right) - _height(node->left) == 2)
    		    {
    		        if(_height(node->right->right) - _height(node->right->left) == 1){
						Node* tmp;
						tmp = __SRRotate(node);
						_root = find_root(tmp);
    		            return tmp;
					}
    		        else{
						Node* tmp;
						tmp = __DRRotate(node);
						_root = find_root(tmp);
    		            return tmp;
					}
    		    }
				_root = find_root(node);
    		   return node;
    		};


// INSERT
			Node* insertInTree(Node* root, const value_type& content, Node* parent)
			{
				if (root == NULL)
				{
					root = _mallocNode.allocate(1);
					_malloc.construct(&root->content, content);
					root->left = NULL;
					root->right = NULL;
					root->isLast = false;
					root->parent = parent;
					if (!_last){
						_last->left = root;
						_last->parent = root;
					}

					root->last = _last;
					root->level = 0;
					// if (!_last){
					// 	_last = _mallocNode.allocate(1);
					// //	_malloc.construct(&_last->content, value_type());
					// 	_last->isLast = true;
					// 	_last->parent = root;
					// 	//root->right = _last;
					// //	_last->content = NULL;
						
					// }
					// else if (_last->parent && _last->parent->content.first < content.first){
					// 	_last->parent = root;
					// 	//root->right = _last;
					// }
				//	std::cout << "PRBLM :" << root->content.second << std::endl; 
				}
				else if (content < root->content)
				{
					root->left = insertInTree(root->left, content, root);
					if (_height(root->left) - _height(root->right) == 2){
					if (content < root->left->content)
						root = __SRRotate(root);
					else
						root = __DRRotate(root);
					}
				}
				else if (content > root->content)
				{
					root->right = insertInTree(root->right, content, root);
					if (_height(root->right) - _height(root->left) == 2){
						if (content > root->right->content)
							root = __SLRotate(root);
						else
							root = __DLRotate(root);
					}
				}
				root->level = std::max(_height(root->left), _height(root->right)) + 1;
				return root;
			}

// CLEAR

			void clear(){
				if (_size){
					__full_clear(_root);
					_size = 0;
					_root = NULL;
				}
			};

			void __full_clear(Node *node){
				if(node == NULL)
        	    			return;
				__full_clear(node->left);
				__full_clear(node->right);
				_malloc.destroy(&node->content);
				_malloc.deallocate(&node->content, 1);
				_mallocNode.destroy(node);
			}


//ROTATIONS
			Node *__SRRotate(Node* &node){
				Node *tmpL = node->left;

				if (tmpL)
					tmpL->parent = node->parent;
				node->left = tmpL->right;
				if (node->left)
					node->left->parent = node;
				tmpL->right = node;
				if (tmpL->right)
					tmpL->right->parent = tmpL;

				node->level = std::max(_height(node->left), _height(node->right)) + 1;
				tmpL->level = std::max(_height(tmpL->left), tmpL->level) + 1;
				return (tmpL);
			}


			Node *__SLRotate(Node* &node){
				Node *tmpR = node->right;

				if (tmpR)
					tmpR->parent = node->parent;
				node->right = tmpR->left;
				if (node->right)
					node->right->parent = node;
				tmpR->left = node;
				if (tmpR->left)
					tmpR->left->parent = tmpR;
				node->level = std::max(_height(node->left), _height(node->right)) + 1;
				tmpR->level = std::max(_height(tmpR->left), tmpR->level) + 1;
				return (tmpR);
			}

			Node* __DLRotate(Node* &node){
    			node->right = __SRRotate(node->right);
    			return (__SLRotate(node));
    		}

    		Node* __DRRotate(Node* &node){
				if (!node->left)
					return node;
    		   	node->left = __SLRotate(node->left);
    		    return (__SRRotate(node));
    		}

			bool isLast(Node* node){
				if (node == _last)
					return true;
				return false;
			}

			iterator lower_bound (const key_type& k){
				iterator it;
			for (iterator it = begin(); it != end(); it++)
			{
				if (!_comp((*it).first, k))
					return it;
			}
			return begin();
			};

			const_iterator lower_bound (const key_type& k) const{
				return (const_iterator(lower_bound(k)));
			};

			iterator upper_bound (const key_type& k){
				iterator it;
			for (it = begin(); it != end(); ++it)
			{
				if (_comp(k, (*it).first))
					return it;
			}
			return begin();
			};

			const_iterator upper_bound (const key_type& k) const{
				return (const_iterator(upper_bound(k)));
			};

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
				return(ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			};

			pair<iterator,iterator>             equal_range (const key_type& k){
				return(ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			};

			template<typename U>
			void Tswap(U &a, U &b){
				U tmp = a;
				a = b;
				b = tmp;
			}		

			void swap (map& x) {
				Tswap(_root, x._root);
				Tswap(_last, x._last);
				Tswap(_size, x._size);
				Tswap(_comp, x._comp);
				Tswap(_malloc, x._malloc);
				Tswap(_mallocNode, x._mallocNode);
			}

			friend bool operator== (const map& lhs, const map& rhs) {
				if (lhs.size() != rhs.size())
					return false;
				iterator itl = lhs.find_min(lhs._root);
				iterator itr = rhs.find_min(rhs._root);
				size_type	i = 0;
				while (i < lhs.size()) {
					if (itl->first != itr->first)
						return false;
					++i;
					itl++;
					itr++;
				}
				return true;
			}

			friend bool operator!= (const map& lhs, const map& rhs) {
				return (!(lhs == rhs));
			}

			friend bool operator<  (const map& lhs, const map& rhs) {
				map	lhsCpy	= lhs;
				map	rhsCpy	= rhs;
				return ft::lexicographical_compare(lhsCpy.begin(), lhsCpy.end(), rhsCpy.begin(), rhsCpy.end());
			}

			friend bool operator<= (const map& lhs, const map& rhs) {
				return !(rhs<lhs);
			}

			friend bool operator>  (const map& lhs, const map& rhs) {
				return rhs < lhs;
			}

			friend bool operator>= (const map& lhs, const map& rhs) {
				return !(lhs<rhs);
			}

	};
}