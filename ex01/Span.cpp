/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:19 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/11 10:39:21 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include "Span.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

Span::Span():
size(0),
numbers()
{ 
	std::cout << GREEN << "Span default constructor called"
			  << C_RESET << '\n';
}

Span::Span(unsigned int size):
size(size),
numbers()
{
	std::cout << GREEN << "Span constructor called"
			  << C_RESET << '\n';
}

Span::Span(const Span& other):
size(other.size),
numbers(other.numbers)
{
	std::cout << GREEN << "Span copy constructor called"
			  << C_RESET << '\n';
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		numbers = rhs.numbers;
	}
	return *this;
}

Span::~Span()
{
	std::cout << RED << "Span destructor called" << C_RESET << '\n';
}

void	Span::addNumber(int newNumber)
{
	if (numbers.size() >= size)
	{
		throw std::exception();
	}
	numbers.push_back(newNumber);
}

static int	getDistance(const int& a, const int& b)
{
	return std::abs(a - b);
}

/* The subject pdf is kinda unclear, and I'm not sure whether I'm supposed to
 * find the span between each adjacent numbers, with the ordering preserved
 * when adding the numbers, or find the span between every number.
 *
 * Therefore, there are 2 versions here.
 *
 * GET_SPAN_OF_ALL will sort the numbers before looking for spans,
 * smallest span is gotten by getting the smallest result of adjacent diffs
 * largest span is gotten from the first and last element
 *
 * if I'd rather get span of adjacents only, then no sorting is needed and we
 * just get the min and max from adjacent diffs
 * */

#define GET_SPAN_OF_ALL
//#define GET_SPAN_OF_ADJACENT

int	Span::shortestSpan()
{
	if (numbers.size() <= 1)
	{
		throw std::exception();
	}
	std::vector<int>	distances;
#if defined GET_SPAN_OF_ALL
	std::vector<int>	sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(),
		std::back_inserter(distances), getDistance);
#elif defined GET_SPAN_OF_ADJACENT
	std::adjacent_difference(numbers.begin(), numbers.end(),
			std::back_inserter(distances), getDistance);
#endif
	return *std::min_element(distances.begin()+1, distances.end());
}

int	Span::longestSpan()
{
	if (numbers.size() <= 1)
	{
		throw std::exception();
	}
#if defined GET_SPAN_OF_ALL
	std::vector<int>	sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int	smallest = *sorted.begin();
	int	biggest = *(sorted.end()-1);
	return getDistance(smallest, biggest);
#elif defined GET_SPAN_OF_ADJACENT
	std::vector<int>	distances;
	std::adjacent_difference(numbers.begin(), numbers.end(),
			std::back_inserter(distances), getDistance);
	return *std::max_element(distances.begin()+1, distances.end());
#endif
}
