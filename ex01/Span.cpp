/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:19 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/10 16:58:34 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <numeric>
#include <cmath>
#include "Span.hpp"

Span::Span():
size(0),
numbers() { }

Span::Span(unsigned int size):
size(size),
numbers(),
distances() { }

Span::Span(const Span& other):
size(other.size),
numbers(other.numbers),
distances(other.distances) { }

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		numbers = rhs.numbers;
		distances = rhs.distances;
	}
	return *this;
}

Span::~Span() { }

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

/* Get the distances between each element by calling std::adjacent_difference()
 * adjacent_difference takes in a range from an InputContainer, grabbing a pair
 * of elements, and calls a function on it, returning a value and storing that
 * in a OutputContainer
 *
 * store the "differences" (distances) and call std::min/max_element() to get
 * shortest and longest span
 * */
void	Span::getDistances()
{
	if (numbers.size() <= 1)
	{
		throw std::exception();
	}
	if (distances.size() != size)
	{
		std::adjacent_difference(numbers.begin(), numbers.end(),
				std::back_inserter(distances), getDistance);
	}
}

int	Span::shortestSpan()
{
	getDistances();
	return *std::min_element(distances.begin()+1, distances.end());
}

int	Span::longestSpan()
{
	getDistances();
	return *std::max_element(distances.begin()+1, distances.end());
}
