/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:22:41 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/10 18:20:37 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename ElemType>
class	MutantStack : public std::stack<ElemType>
{
public:
	typedef typename std::stack<ElemType>			stack;
	typedef typename stack::container_type			c_type;
	typedef typename c_type::iterator				iterator;
	typedef typename c_type::const_iterator			const_iterator;
	typedef typename c_type::reverse_iterator		reverse_iterator;
	typedef typename c_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack&);
	MutantStack&	operator=(const MutantStack&);
	~MutantStack();

	iterator				begin();
	iterator				end();
	const_iterator			cbegin() const;
	const_iterator			cend() const;
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	crbegin() const;
	const_reverse_iterator	crend() const;
};

namespace
{
	const char* GREEN = "\033[0;32m";
	const char* RED = "\033[0;31m";
	const char* C_RESET = "\033[0m";
}

/* Default constructor */
template<typename ElemType>
MutantStack<ElemType>::MutantStack()
{ 
	std::cout << GREEN << "MutantStack default constructor called"
			  << C_RESET << '\n';
}

/* Copy constructor */
template<typename ElemType>
MutantStack<ElemType>::MutantStack(const MutantStack& other):
std::stack<ElemType>(other)
{
	std::cout << GREEN << "MutantStack copy constructor called"
			  << C_RESET << '\n';
}

/* Copy assignment operator
 * c is the name of the member variable of the underlying container (default: deque)
 * implementing the stack */
template<typename ElemType>
MutantStack<ElemType>&	MutantStack<ElemType>::operator=(const MutantStack& other)
{
	std::cout << GREEN << "MutantStack copy assignment operator called"
			  << C_RESET << '\n';
	this->c = other.c;
	return *this;
}

/* Destructor */
template<typename ElemType>
MutantStack<ElemType>::~MutantStack()
{
	std::cout << RED << "MutantStack destructor called" << C_RESET << '\n';
}

template<typename ElemType>
typename MutantStack<ElemType>::iterator	MutantStack<ElemType>::begin()
{
	return this->c.begin();
}

template<typename ElemType>
typename MutantStack<ElemType>::iterator	MutantStack<ElemType>::end()
{
	return this->c.end();
}

/* Standard containers only have .cbegin() from C++11 */
template<typename ElemType>
typename MutantStack<ElemType>::const_iterator	MutantStack<ElemType>::cbegin() const
{
	return this->c.begin();
}

/* Standard containers only have .cend() from C++11 */
template<typename ElemType>
typename MutantStack<ElemType>::const_iterator	MutantStack<ElemType>::cend() const
{
	return this->c.end();
}

template<typename ElemType>
typename MutantStack<ElemType>::reverse_iterator	MutantStack<ElemType>::rbegin()
{
	return this->c.rbegin();
}

template<typename ElemType>
typename MutantStack<ElemType>::reverse_iterator	MutantStack<ElemType>::rend()
{
	return this->c.rend();
}

/* Standard containers only have .crbegin() from C++11 */
template<typename ElemType>
typename MutantStack<ElemType>::const_reverse_iterator	MutantStack<ElemType>::crbegin() const
{
	return this->c.rbegin();
}

/* Standard containers only have .crend() from C++11 */
template<typename ElemType>
typename MutantStack<ElemType>::const_reverse_iterator	MutantStack<ElemType>::crend() const
{
	return this->c.rend();
}

#endif
