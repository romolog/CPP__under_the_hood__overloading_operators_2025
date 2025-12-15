/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:02:37 by rponomar          #+#    #+#             */
/*   Updated: 2025/05/06 15:18:58 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

template <typename T>
	fxp::Fixed	fxp::operator+(const T lhs, fxp::Fixed const rhs)
{	
	int rhs_value = rhs.getRawBits();
	int lhs_value = (lhs * rhs.fract_power());
	if ((rhs_value > 0 && lhs_value > __INT_MAX__ - rhs_value) || \
		(rhs_value < 0 && lhs_value < -1 - __INT_MAX__ - rhs_value))
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;	
	fxp::Fixed	res(lhs + (double)rhs);
	return (res);
}

template <typename T>
	fxp::Fixed	fxp::operator+(const fxp::Fixed lhs, const T rhs)
{	
	int rhs_value = rhs * lhs.fract_power();
	int lhs_value = lhs.getRawBits();
	if ((rhs_value > 0 && lhs_value > __INT_MAX__ - rhs_value) || \
		(rhs_value < 0 && lhs_value < -1 - __INT_MAX__ - rhs_value))
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;	
	fxp::Fixed	res((double)lhs + rhs);
	return (res);
}

template <typename T>
	fxp::Fixed	fxp::operator-(const T lhs, fxp::Fixed const rhs)
{	
	int rhs_value = rhs.getRawBits();
	int lhs_value = (lhs * rhs.fract_power());
	if ((rhs_value > 0 && lhs_value < - 1 - __INT_MAX__ + rhs_value) || \
		(rhs_value < 0 && lhs_value > __INT_MAX__ + rhs_value))
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;	
	fxp::Fixed	res(lhs + (double)rhs);
	return (res);
}

template <typename T>
	fxp::Fixed	fxp::operator-(const fxp::Fixed lhs, const T rhs)
{	
	int rhs_value = rhs * lhs.fract_power();
	int lhs_value = lhs.getRawBits();
	if ((rhs_value > 0 && lhs_value < - 1 - __INT_MAX__ + rhs_value) || \
		(rhs_value < 0 && lhs_value > __INT_MAX__ + rhs_value))
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;	
	fxp::Fixed	res((double)lhs + rhs);
	return (res);
}

int	main(void)
{
	fxp::Fixed			a;
	fxp::Fixed const	b( fxp::Fixed( 5.05f ) * fxp::Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;	
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << fxp::Fixed::max( a, b) << std::endl;

	char prev = std::cout.fill('-');
	std::cout << std::setw(30) << "" << std::endl;
	std::cout.fill(prev);

	std::cout << "Min a : b = " << fxp::Fixed::min( a, b) << std::endl;

	fxp::Fixed	c (-2.4);
	fxp::Fixed	d (-2.5);

	std::cout << "Max c : d = " << fxp::Fixed::max( c, d) << std::endl;
	std::cout << "Min c : d = " << fxp::Fixed::min( c, d) << std::endl;

	c = 1.5;
	std::cout << std::endl << "c = " << c << std::endl;
	
	fxp::Fixed	e (1.5);
	// std::cout << "e = " << e << std::endl;

	std::cout << "c + c = " << c + c << std::endl;		
	std::cout << "c + 1 = " << c + 1 << std::endl;
	std::cout << "1 + c = " << 1 + c << std::endl;
	std::cout << "c - 1.25 = " << c - 1.25 << std::endl;
	std::cout << "(c += 1.25) = " << (c += 1.25) << std::endl;
	std::cout << "-4.25 + c = " << -4.25 + c << std::endl;

	std::cout << "c - c = " << c - c << std::endl;
	c = 1.5;
	std::cout << std::endl << "c = " << c << std::endl;

	std::cout << "2 * c = " << 2 * c << std::endl;

	// std::cout << c / -2 << std::endl;
			
	
	return 0;
}


	// using fxp::operator+;