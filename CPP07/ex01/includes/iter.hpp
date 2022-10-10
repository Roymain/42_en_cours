/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:00:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 23:16:47 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template<typename T>
void	acc(T& elem)
{
	++elem;
}

template<typename T>
void	aff(const T& elem)
{
	std::cout << elem << " ";
}

template <typename T>
void    iter(const T *tab, size_t size, void (*f)(const T&)){
    for (size_t i = 0; i < size; i++)
    {
        f(tab[i]);
    }
}

template <typename T>
void    iter(T *tab, size_t size, void (*f)(T&)){
    for (size_t i = 0; i < size; i++)
    {
        f(tab[i]);
    }
}

template<typename T>
void	print_array(const T* array, const size_t len)
{
	iter(array, len, aff);
	std::cout << std::endl;
}
