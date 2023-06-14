/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:00:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 03:24:52 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>

class Span {
		private :
					std::vector<int>	_data;
					unsigned int		_size;
		public	:
					void				addNumber( int value );
					unsigned int		shortestSpan();
					unsigned int		longestSpan();
		
					Span(const Span& ref);
					Span&	operator=(const Span& ref);

					Span();
					Span( unsigned int n );
					~Span();

					class SpanFullException: public std::exception
					{
						const char*	what() const throw()
						{
							return ("SpanFullException");
						}
					};
					class SpanEmptySetException: public std::exception
					{
						const char*	what() const throw()
						{
							return ("SpanEmptySetException");
						}
					};

					template <typename T>
					void	addNumber(T start, T end)
					{
						if (_data.size() + end - start > _size)
							throw SpanFullException();
						_data.insert(_data.begin(), start, end);
						std::sort(_data.begin(), _data.end());
					}
};
