/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:25:53 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/15 21:41:04 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::operator=( const Fixed& other )
{
	//std::cout	<< "Copy assignment operator called"
	//			<< std::endl;

	if (this != &other)
		this->_value = other._value;

	return (*this);
}

bool	Fixed::operator>( const Fixed& other ) const
{
	//std::cout	<< "Greater than operator called"
	//			<< std::endl;

	if (this->_value > other._value)
		return (true);

	return (false);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	//std::cout	<< "Lower than operator called"
	//			<< std::endl;

	if (this->_value < other._value)
		return (true);

	return (false);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	//std::cout	<< "Greater than or equal to operator called"
	//			<< std::endl;

	if (this->_value >= other._value)
		return (true);

	return (false);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	//std::cout	<< "Lower than or equal to operator called"
	//			<< std::endl;

	if (this->_value <= other._value)
		return (true);

	return (false);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	//std::cout	<< "Equal to operator called"
	//			<< std::endl;

	if (this->_value == other._value)
		return (true);

	return (false);
}

Fixed	Fixed::operator+( const Fixed& other ) const
{
	Fixed sum;

	//std::cout	<< "Addition operator called"
	//			<< std::endl;

	sum._value = this->_value + other._value;
	return (sum);
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	Fixed sub;

	//std::cout	<< "Subtraction operator called"
	//			<< std::endl;

	sub._value = this->_value - other._value;
	return (sub);
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	float	left = (float)this->_value / (1 << _fractional_bits);
	float	right = (float)other._value / (1 << _fractional_bits);
	Fixed mul;

	//std::cout	<< "Multiplication operation called"
	//			<< std::endl;
	
	mul._value = (left * right) * (1 << _fractional_bits);
	return (mul);
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	float	left = (float)this->_value / (1 << _fractional_bits);
	float	right = (float)other._value / (1 << _fractional_bits);
	Fixed div;

	//std::cout	<< "Division operation called"
	//			<< std::endl;
	
	div._value = (left / right) * (1 << _fractional_bits);
	return (div);
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

Fixed::Fixed() :
	_value(0)
{
	//std::cout	<< "Default constructor called"
	//			<< std::endl;
}

Fixed::Fixed( const Fixed& other )
{
	//std::cout	<< "Copy constructor called"
	//			<< std::endl;
	*this = other;
}

Fixed::Fixed( const int c_int )
{
	//std::cout	<< "Int constructor called"
	//			<<	std::endl;

	this->_value = c_int << _fractional_bits;
}

Fixed::Fixed( const float c_float )
{
	//std::cout	<< "Float constructor called"
	//			<<	std::endl;

	this->_value = (int)((roundf( c_float * (1 << _fractional_bits))));
}

Fixed::~Fixed()
{
	//std::cout	<< "Destructor called"
	//			<< std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout	<< "setRawBits member function called"
	//			<< std::endl;

	this->_value = raw;
}

int		Fixed::getRawBits( void ) const
{	
	//std::cout	<< "getRawBits member function called"
	//			<< std::endl;

	return (this->_value);
}

float	Fixed::toFloat( void ) const
{
	return ((float) this->_value) / (1 << _fractional_bits);
}

int		Fixed::toInt( void ) const
{
	return ((int) (this->_value >> _fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out	<< fixed.toFloat();
	return (out);
}
