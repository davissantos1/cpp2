/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:17 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/12 15:29:23 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_value;
		static const int _fractional_bits = 8;
		
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};	
#endif
