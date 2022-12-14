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
#include <algorithm>

namespace ft {
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > > 
	class map {

		private:
			struct  Node {
				pair<const Key, T>				content;
				Node*                           parent;
				Node*							left;
				Node*							right;
				long long int                   level;
			};

		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef pair<const key_type, mapped_type>		value_type;
			typedef std::size_t					size_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef T&							reference;
			typedef const T&					const_reference;
			typedef T*							pointer;
			typedef const T*					const_pointer;



		public:

			typedef ft::MapIterator<Key, T, Compare, Node>							iterator;
			typedef ft::MapIterator<Key, T, Compare, Node>					const_iterator;
			typedef	ft::reverse_iterator<iterator>											reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>									const_reverse_iterator;

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

			value_compare getValue_compareComp() const { return (value_compare(key_compare()));}


		private:
			allocator_type						_malloc;
			std::allocator<Node>				_mallocNode;
			Node*								_root;
			Node*								_last;
			size_type							_size;
			key_compare							_comp;


		public:
	//		map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _size(0), _malloc(alloc), _comp(comp), _root(NULL){};

			explicit map( const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _size(0), _malloc(alloc), _comp(comp), _root(NULL), _last(NULL){};

			template<class InputIt>
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			~map(){};

		Node* find_min(Node* t){
			if (!t)
				return (NULL);
			else if (!t->left)
				return (t);
			else
			        return find_min(t->left);
		}

			iterator begin() { return iterator(find_min(_root), _comp);}

			Node* getRoot(){return _root;}


// MODIFIERS
			ft::pair<iterator, bool> insert( const value_type& value ){
				Node *t = _root;

				_root = insertInTree(_root, value, NULL);
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(_root, _comp), true));
			};

			/* @Brief Extends the container by inserting new elements*/
			/* @Param  const value_type &val*/
			/* @Return  iterator*/
			iterator insert (iterator position, const value_type& val){
				position = NULL;
				iterator it(_root = insertInTree(_root, val));
				_size++;
				return (it);
			}

			// template< class InputIt >
			// void insert( InputIt first, InputIt last,
		    // typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){

			// };

// INSERTION
			long long int _height(Node* temp){
        			int h = 0;
				if (temp != NULL)
				{
					int l_height = _height(temp->left);
					int r_height = _height(temp->right);
					int max_height = std::max(l_height, r_height);
					h = max_height + 1;
				}
				return h;
			}

			/*
			* _Height Difference
			*/
			int diff(Node *temp)
			{
				int l_height = _height(temp->left);
				int r_height = _height(temp->right);
				int b_factor = l_height - r_height;
				return b_factor;
			}

			Node*	balance(Node *temp)
			{
				int bal_factor = diff(temp);
				if (bal_factor > 1)
				{
					if (diff(temp->left) > 0)
						temp = ll_rotation(temp);
					else
						temp = lr_rotation(temp);
				}
				else if (bal_factor < -1)
				{
					if (diff(temp->right) > 0)
						temp = rl_rotation(temp);
					else
						temp = rr_rotation(temp);
				}
				return temp;
			}


			Node* insertInTree(Node* root, const value_type& content, Node* parent)
			{
				if (_root)
					std::cout << _root->content.first << std::endl;
				if (root == NULL)
				{
					std::cout << "hihi\n";
					root = _mallocNode.allocate(1);
					_malloc.construct(&root->content, content);
					root->left = NULL;
					root->right = NULL;
					root->parent = parent;
					root->level = 0;
					if (!_last || _last->content.first < content.first)
						_last = root;
					root->parent = parent;
				}
				else if (content.first < root->content.first)
				{
					root->left = insertInTree(root->left, content, root);
					// if (_height(root->left) - _height(root->right) == 2){
					// if (content < root->left->content)
					// 	root = __SRRotate(root);
					// else
					// 	root = __DRRotate(root);
					// }
					root = balance(root);
				}
				else if (content.first >= root->content.first)
				{
					root->right = insertInTree(root->right, content, root);
					// if (_height(root->right) - _height(root->left) == 2){
					// 	if (content > root->right->content)
					// 		root = __SLRotate(root);
					// 	else
					// 		root = __DLRotate(root);
					// }
					root = balance(root);
				}
				//root->level = std::max(_height(root->left), _height(root->right)) + 1;
				return root;
			}

//ROTATIONS

			/*
			* Right- Right Rotation
			*/
			Node* rr_rotation(Node* parent)
			{
				Node* temp;
				temp = parent->right;
				parent->right = temp->left;
				temp->left = parent;
				return temp;
			}
			/*
			* Left- Left Rotation
			*/
			Node* ll_rotation(Node* parent)
			{
				Node* temp;
				temp = parent->left;
				parent->left = temp->right;
				temp->right = parent;
				return temp;
			}

			/*
			* Left - Right Rotation
			*/
			Node* lr_rotation(Node* parent)
			{
				Node* temp;
				temp = parent->left;
				parent->left = rr_rotation(temp);
				// parent->level = std::max(_height(parent->left), _height(parent->right)) + 1;
				// temp->level = std::max(_height(temp->left), temp->level) + 1;
				return ll_rotation(parent);
			}

			/*
			* Right- Left Rotation
			*/
			Node* rl_rotation(Node* parent)
			{
				Node* temp;
				temp = parent->right;
				parent->right = ll_rotation(temp);
				// parent->level = std::max(_height(parent->left), _height(parent->right)) + 1;
				// temp->level = std::max(_height(temp->left), temp->level) + 1;
				return rr_rotation(parent);
			}


		// 	Node *__SRRotate(Node* &t){
		// 	Node *u = t->left;

		// 	if (u)
		// 		u->parent = t->parent;
		// 	t->left = u->right;
		// 	if (t->left)
		// 		t->left->parent = t;
		// 	u->right = t;
		// 	if (u->right)
		// 		u->right->parent = u;

		// 	t->level = std::max(_height(t->left), _height(t->right)) + 1;
		// 	u->level = std::max(_height(u->left), u->level) + 1;
		// 	return (u);
		// }

		// /* @Brief clear all the tree without us iterator  for faster */
		// /* @Param Node *t */
		// /* @Return None */
		// void __full_clear(Node *t){
		// 	if(t == NULL)
        //     			return;
		// 	__full_clear(t->left);
		// 	__deallocateNode(t);
		// 	__full_clear(t->right);
		// }

		// /* @Brief rotation of the node left*/
		// /*      	  Q                                 P     */     
 		// /*               / \          LEFT ROTATION        / \    */    
 		// /*              P   C    <<<-------------------   A   Q   */   
 		// /*             / \                                   / \  */  
 		// /*            A   B                                 B   C */ 
		// /* @Param  Node* &t*/
		// /* @Return  Node**/
		// Node *__SLRotate(Node* &t){
		// 	Node *u = t->right;

		// 	if (u)
		// 		u->parent = t->parent;
		// 	t->right = u->left;
		// 	if (t->right)
		// 		t->right->parent = t;
		// 	u->left = t;
		// 	if (u->left)
		// 		u->left->parent = u;
		// 	t->level = std::max(_height(t->left), _height(t->right)) + 1;
		// 	u->level = std::max(_height(u->left), u->level) + 1;
		// 	return (u);
		// }

		// /* @Brief Make double rotation left*/
		// /* @Param  Node *t */
		// /* @Return  Node*/
		// Node* __DLRotate(Node* &t){
    	// 	    	t->right = __SRRotate(t->right);
    	// 	    	return (__SLRotate(t));
    	// 	}

		// /* @Brief Make double rotation right*/
		// /* @Param  Node *t */
		// /* @Return  Node*/
    	// 	Node* __DRRotate(Node* &t){
    	// 	   	t->left = __SLRotate(t->left);
    	// 	    	return (__SRRotate(t));
    	// 	}




	};
};