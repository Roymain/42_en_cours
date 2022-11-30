#pragma once


#include "VectorIterator.hpp"
#include <memory>
#include <iostream>
#include <iterator>
#include "../Integral.hpp"
#include "../Equal.hpp"
#include "../Pair.hpp"
#include "../ReverseIterator.hpp"
#include "../IteratorTraits.hpp"

namespace ft {
	template
	<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > >
	class map {

		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef std::pair<const Key, T>		value_type;
			typedef std::size_t					size_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef	value_type&					reference;
			typedef	const value_type&		 	const_reference;
			typedef	Allocator::pointer			pointer;
			typedef	Allocator::const_pointer		const_pointer;
//			typedef LegacyBidirectionalIterator to value_type		iterator;
//			typedef	LegacyBidirectionalIterator to const value_type		const_iterator;
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

		private:
			struct  Node {
				ft::pair<const Key, T>			content;
				Node                            *parent;
				Node							*left;
				Node							*right;
				long long int                   level;
			};
			allocator_type						_malloc
			std::allocator<node>				_mallocNode;
			Node								*_root;
			size_type							_size;
			key_compare							_comp;


		public:
			map(): _size(0), _malloc(std::allocator()), _comp(NULL), _root(NULL){};

			explicit map( const Compare& comp, const Allocator& alloc = Allocator()) : _size(0), _malloc(alloc), _comp(comp), _root(NULL){};

			template<class InputIt>
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );




// MODIFIERS
			std::pair<iterator, bool> insert( const value_type& value ){

			};

			template< class InputIt >
			void insert( InputIt first, InputIt last );
	};
};