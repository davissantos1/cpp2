/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:25:53 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/12 15:29:41 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;

	if (this != &other)
		this->_value = other._value;

	return (*this);
}

Fixed::Fixed() :
	_value(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Fixed::Fixed( const Fixed& other )
{
	*this = other;
	std::cout	<< "Copy constructor called"
				<< std::endl;
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout	<< "setRawBits member function called"
				<< std::endl;

	this->_value = raw;
}

int		Fixed::getRawBits( void ) const
{	
	std::cout	<< "getRawBits member function called"
				<< std::endl;

	return (this->_value);
}
