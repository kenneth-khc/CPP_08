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
#include <iterator>

template<typename ElemType>
class	MutantStack : public std::stack<ElemType>
{
public:
	typedef typename std::stack<ElemType>			stack;
	typedef typename stack::container_type			deque;
	typedef typename deque::iterator				iterator;
	typedef typename deque::const_iterator			const_iterator;
	typedef typename deque::reverse_iterator		reverse_iterator;
	typedef typename deque::const_reverse_iterator	const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack&);
	MutantStack&	operator=(const MutantStack&);
	~MutantStack();

	iterator				begin();
	iterator				end();
	const_iterator			cbegin();
	const_iterator			cend();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	crbegin();
	const_reverse_iterator	crend();
};

/* Default constructor */
template<typename ElemType>
MutantStack<ElemType>::MutantStack()
{ 
	std::cout << "MutantStack default constructor called\n";
}

/* Copy constructor */
template<typename ElemType>
MutantStack<ElemType>::MutantStack(const MutantStack& other):
std::stack<ElemType>(other)
{
	std::cout << "MutantStack copy constructor called\n";
}

/* Copy assignment operator
 * c is the name of the member variable of the underlying container (deque)
 * implementing the stack */
template<typename ElemType>
MutantStack<ElemType>&	MutantStack<ElemType>::operator=(const MutantStack& other)
{
	std::cout << "MutantStack copy assignment operator called\n";
	this->c = other.c;
	return *this;
}

/* Destructor */
template<typename ElemType>
MutantStack<ElemType>::~MutantStack()
{
	std::cout << "MutantStack destructor called\n";
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

template<typename ElemType>
typename MutantStack<ElemType>::const_iterator	MutantStack<ElemType>::cbegin()
{
	return this->c.cbegin();
}

template<typename ElemType>
typename MutantStack<ElemType>::const_iterator	MutantStack<ElemType>::cend()
{
	return this->c.cend();
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

template<typename ElemType>
typename MutantStack<ElemType>::const_reverse_iterator	MutantStack<ElemType>::crbegin()
{
	return this->c.crbegin();
}

template<typename ElemType>
typename MutantStack<ElemType>::const_reverse_iterator	MutantStack<ElemType>::crend()
{
	return this->c.crend();
}

#endif
