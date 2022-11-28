#pragma once


#include "VectorIterator.hpp"
#include <memory>
#include <iostream>
#include <iterator>
#include "../Integral.hpp"
#include "../ReverseIterator.hpp"
#include "../IteratorTraits.hpp"

namespace ft {
	template
	<class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>>
	class map {
		public:
			typedef Key		key_type;
			typedef T		mapped_type;
			typedef std::pair<const Key, T>		value_type;
			typedef Unsigned integer type (usually std::size_t)		size_type;
			typedef	Signed integer type (usually std::ptrdiff_t)	difference_type;
			typedef	Compare		key_compare;
			typedef	Allocator	allocator_type;
			typedef	value_type&		reference;
			typedef	const value_type&		 const_reference;
			typedef	Allocator::pointer	(until C++11)		pointer;
			typedef	Allocator::const_pointer		const_pointer;
//			typedef LegacyBidirectionalIterator to value_type		iterator;
//			typedef	LegacyBidirectionalIterator to const value_type		const_iterator;
			typedef	ft::reverse_iterator<iterator>		reverse_iterator;
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

		public:

	};
};