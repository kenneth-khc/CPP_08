/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:53:43 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/10 16:58:37 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

class	Span
{
public:
	Span(); // default constructor
	Span(unsigned int);
	Span(const Span&); // copy constructor
	Span&	operator=(const Span&); // copy assignment operator
	~Span(); // destructor

	void	addNumber(int);
	/*void	getDistances();*/
	int		shortestSpan();
	int		longestSpan();

	template<typename InputIt>
	void	addNumbersFromRange(InputIt, InputIt);

private:
	unsigned int		size;
	std::vector<int>	numbers;
};

template<typename InputIt>
void	Span::addNumbersFromRange(InputIt begin, InputIt end)
{
	for (InputIt it = begin; it != end; ++it)
	{
		if (numbers.size() >= size)
		{
			throw std::exception();
		}
		numbers.push_back(*it);
	}
}

#endif
