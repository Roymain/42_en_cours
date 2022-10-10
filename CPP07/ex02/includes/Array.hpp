/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:00:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 23:40:31 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template <typename T>
class Array {
    private:
            T               *_tab;
            unsigned int    _size;
            
    public :
            T&	operator[](const unsigned int pos)
            {
                if (pos >= this->_size)
                    throw ArrayException();
                return (this->_tab[pos]);
            };

            const T&	operator[](const unsigned int pos) const
            {
                if (pos >= this->_size)
                    throw ArrayException();
                return (this->_tab[pos]);
            };

            unsigned int	size() const
            {
                return (this->_size);
            };

            
            Array( const Array &array) : _tab(new T[array._size]), _size(array._size){
                for (unsigned int i = 0; i < array._size; i++)
                {
                    this->_tab[i] = array._tab[i];
                }
            };
            
            Array & operator = (const Array &rhs){
                if (&rhs != this)
                {
                    this->_size = rhs._size;
                    delete []_tab;
                    _tab = new T[_size];
                    for (unsigned int i = 0; i < rhs._size; i++)
                    {
                        this->_tab[i] = rhs._tab[i];
                    }
                }
                return (*this);
            };
            

            class ArrayException: public std::exception
            {
                public:
                const char*	what() const throw()
                {
                    return ("ArrayException: Overflow on Array");
                }
            };
            
            Array() : _tab(NULL), _size(0){};
            Array( unsigned int n ) : _tab(new T[n]), _size(n){};
            ~Array(){
                delete []_tab;
            };
            
};