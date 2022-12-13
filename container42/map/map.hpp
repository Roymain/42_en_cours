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
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > > 
	class map {

		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef ft::pair<const Key, T>		value_type;
			typedef std::size_t					size_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;


		private:
			struct  Node {
				value_type						content;
				Node                            *parent;
				Node							*left;
				Node							*right;
				long long int                   level;
			};

		public:

			typedef typename ft::MapIterator<Key, T, Compare, Node>							iterator;
			typedef typename ft::MapIterator<const Key, T, Compare, Node>					const_iterator;
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

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
			size_type							_size;
			key_compare							_comp;


		public:
		//	map(): _size(0), _malloc(std::allocator()), _comp(NULL), _root(NULL){};

			explicit map( const Compare& comp, const Allocator& alloc = Allocator()) : _size(0), _malloc(alloc), _comp(comp), _root(NULL){};

			template<class InputIt>
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );



			iterator begin() { return iterator(find_min(_root), _comp);}


// MODIFIERS
			ft::pair<iterator, bool> insert( const value_type& value ){
				Node *t = __search_key(_root,  value.first);
				if (t){
					return (ft::make_pair<iterator, bool>(iterator(t, _comp), false));
				}
				_root = __avl_insert(this->_root, value, NULL);
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(_root, _comp), true));
			};

			/* @Brief Extends the container by inserting new elements*/
			/* @Param  const value_type &val*/
			/* @Return  iterator*/
			iterator insert (iterator position, const value_type& val){
				position = NULL;
				iterator it(_root = __avl_insert(_root, val, NULL));
				_size++;
				return (it);
			}

			// template< class InputIt >
			// void insert( InputIt first, InputIt last,
		    // typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){

			// };

// INSERTION
			int _height(Node *temp)
			{
				int h = 0;
				if (temp != NULL)
				{
					int l_height = _height(temp->left);
					int r_height = _height(temp->right);
					int max__height = std::max(l_height, r_height);
					h = max__height + 1;
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


			Node* insertInTree(Node *root, value_type content)
			{
				if (root == NULL)
				{
					root = new Node;
					root->data = content;
					root->left = NULL;
					root->right = NULL;
					return root;
				}
				else if (content < root->data)
				{
					root->left = insertInTree(root->left, content);
					root = balance(root);
				}
				else if (content >= root->data)
				{
					root->right = insertinTree(root->right, content);
					root = balance(root);
				}
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
				return rr_rotation(parent);
			}
	};
};