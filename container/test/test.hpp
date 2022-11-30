/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:26:20 by aartiges          #+#    #+#             */
/*   Updated: 2022/11/26 03:56:48 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST
# define FT_TEST

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

/******************************************************************************/
/***************************       Test for time    ***************************/
/******************************************************************************/

# define TEST_FILE_TIME "time"

# include <sys/time.h>
# include <fstream>

/******************************************************************************/
/***************************      Environnement     ***************************/
/******************************************************************************/

# define STR_IMPL(A) #A
# define STR(A) STR_IMPL(A)

# define DIR_INCLUDES ..

/******************************************************************************/
/***************************          Tools         ***************************/
/******************************************************************************/

/*
equal
lexicographical_compare
*/
# define HEADER_ALGORITHM Equal.hpp

/*
pair
make_pair
*/
# define HEADER_PAIR Pair.hpp

/*
is_integral
enable_if
*/
# define HEADER_TRAITS Integral.hpp

/******************************************************************************/
/***************************        Iterators       ***************************/
/******************************************************************************/

/*
iterators_traits
*/
# define HEADER_ITERATORS_TRAITS IteratorTraits.hpp

/*
reverse_iterator
*/
# define HEADER_REVERSE_ITERATOR ReverseIterator.hpp

/******************************************************************************/
/***************************       Containers       ***************************/
/******************************************************************************/

/*
stack
*/
# define HEADER_STACK Stack.hpp

/*
vector
*/
# define HEADER_VECTOR vector/Vector.hpp

/*
map
*/
# define HEADER_MAP map/map.hpp

#endif