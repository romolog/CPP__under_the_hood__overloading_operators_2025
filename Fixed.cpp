/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:04:07 by rponomar          #+#    #+#             */
/*   Updated: 2025/05/06 14:59:22 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cmath>

//	TOOL FUNCTIONS ------------------------------------------------------------
int		fxp::Fixed::getRawBits(void) const
{
	return num_value;
}

void	fxp::Fixed::setRawBits(int const raw)
{
	num_value = raw;
}

double		fxp::Fixed::fract_min(void) const
{
	double res = 1.0;
	int i = 0;
	for(; i < fract_bits; i++)
		res /=2;
	return (res);
}

int		fxp::Fixed::fract_power(void) const
{
	int res = 1;
	int i = 0;
	for(; i < fract_bits; i++)
		res *=2;
	return (res);
}

//	CTOR-DEFAULT ------------------------------------------------------------
fxp::Fixed::Fixed()
{
	num_value = 0;
}

//	DTOR-DEFAULT ------------------------------------------------------------
fxp::Fixed::~Fixed() {}

//	COPY-CTOR ---------------------------------------------------------------
fxp::Fixed::Fixed(const fxp::Fixed& rhs)
{
	num_value = rhs.getRawBits();
}

//	COPY-ASSIGNMENT ---------------------------------------------------------
fxp::Fixed& fxp::Fixed::operator=(const fxp::Fixed& rhs)
{
	if (this == &rhs) return (*this);
	num_value = rhs.getRawBits();
	return (*this);
}

//	CTOR-DIRECT-INT ---------------------------------------------------------
fxp::Fixed::Fixed(const int v)
{
	int frpw = fract_power();
	if (v * frpw / frpw != v)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	num_value = v * frpw;
	if (v < 0 && num_value > 0)
		num_value *= -1;
}

//	CTOR-DIRECT-DOUBLE ---------------------------------------------------------
fxp::Fixed::Fixed(const double f)
{
	int intg = (int)f;
	int	frpw = fract_power();
	if (intg * frpw / frpw != intg)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	double frmin = fract_min();
	num_value = (int)(f / frmin);
	double diff = f - num_value * frmin;
	if ((f > 0 && diff > frmin - diff) \
		|| (f < 0 && diff && diff < frmin - diff))
		num_value++;
}

//	CAST-TO-DOUBLE ---------------------------------------------------------
double fxp::Fixed::ft_operator_double(void) const
{
	if (!num_value) 
		return (0.0);
	double frmin = fract_min();
	return (frmin * num_value);
}

fxp::Fixed::operator double ()
{
	return (ft_operator_double());
}

fxp::Fixed::operator double () const
{
	return (ft_operator_double());
}

//	OPERATORS --------------------------------------------------------- OPERATORS ---------------------------------------------------------
fxp::Fixed&	fxp::Fixed::operator++()
{
	if (num_value == __INT_MAX__)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	num_value += 1;
	return (*this);
}

fxp::Fixed	fxp::Fixed::operator++(int)
{
	if (num_value == __INT_MAX__)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	fxp::Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

fxp::Fixed&	fxp::Fixed::operator--()
{
	if (num_value == -1 - __INT_MAX__)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;	
	num_value -= 1;
	return (*this);
}

fxp::Fixed	fxp::Fixed::operator--(int)
{
	if (num_value == -1 - __INT_MAX__)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	fxp::Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

//	PLUS -------------------------------------------------------------- PLUS
fxp::Fixed&	fxp::Fixed::operator+=(const Fixed& rhs)
{	
	if ((num_value + rhs.num_value) - rhs.num_value != num_value)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	num_value += rhs.num_value;
	return (*this);
}


fxp::Fixed	fxp::Fixed::operator+(const Fixed& rhs)
{	
	if ((num_value + rhs.num_value) - rhs.num_value != num_value)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	fxp::Fixed	tmp(*this);
		tmp += rhs;
	return (tmp);
}

//	MINUS -------------------------------------------------------------- MINUS
fxp::Fixed&	fxp::Fixed::operator-=(const Fixed& rhs)
{
	if ((num_value - rhs.num_value) + rhs.num_value != num_value)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	num_value -= rhs.num_value;
	return (*this);
}

fxp::Fixed	fxp::Fixed::operator-(const Fixed& rhs)
{	
	if ((num_value - rhs.num_value) + rhs.num_value != num_value)
		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
	fxp::Fixed	tmp(*this);
		tmp -= rhs;
	return (tmp);
}


//	MULTIPLY -------------------------------------------------------------- MULTIPLY
// fxp::Fixed	fxp::operator-(const fxp::Fixed lhs, const fxp::Fixed rhs)
// {	
// 	if ((lhs.getRawBits() - rhs.getRawBits()) + rhs.getRawBits() != lhs.getRawBits())
// 		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
// 	fxp::Fixed	tmp(lhs);	
// 		tmp -= rhs;
// 	return (tmp);
// }

// fxp::Fixed&	fxp::Fixed::operator*=(const Fixed& rhs)
// {
// 	double tmp = (double)(*this) * (double)rhs;
// 	if (tmp / (double)(*this) != (double)rhs)
// 		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
// 	fxp::Fixed	res(tmp);
// 	num_value = res.num_value;
// 	return (*this);
// }

// fxp::Fixed	fxp::operator*(const fxp::Fixed lhs, const fxp::Fixed rhs)
// {	
// 	double tmp = (double)lhs * (double)rhs;
// 	if (tmp / (double)lhs != (double)rhs)
// 		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }


// template <typename T>
// fxp::Fixed	fxp::operator*(const fxp::Fixed lhs, const T rhs)
// {	
// 	double tmp = (double)lhs * rhs;
// 	if (tmp / (double)lhs != (double)rhs)
// 		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }

// template <typename T>
// fxp::Fixed	fxp::operator*(const T lhs, const fxp::Fixed rhs)
// {	
// 	double tmp = lhs * (double)rhs;
// 	if (tmp / lhs != (double)rhs)
// 		std::cerr << "fxp::Fixed: Warning: overflow" << std::endl;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }

// fxp::Fixed&	fxp::Fixed::operator/=(const Fixed& rhs)
// {
// 	if ((double)rhs == 0)
// 		std::cerr << "fxp::Fixed: Error: devision by zero" << std::endl;
// 	double tmp = (double)(*this) / (double)rhs;
// 	fxp::Fixed	res(tmp);
// 	num_value = res.num_value;
// 	return (*this);
// }

// fxp::Fixed	fxp::operator/(const fxp::Fixed lhs, const fxp::Fixed rhs)
// {	
// 	if ((double)rhs == 0)
// 		std::cerr << "fxp::Fixed: Error: devision by zero" << std::endl;
// 	double tmp = (double)lhs / (double)rhs;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }

// template <typename T>
// fxp::Fixed	fxp::operator/(const fxp::Fixed lhs, const T rhs)
// {	
// 	if ((double)rhs == 0)
// 		std::cerr << "fxp::Fixed: Error: devision by zero" << std::endl;	
// 	double tmp = (double)lhs / rhs;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }

// template <typename T>
// fxp::Fixed	fxp::operator/(const T lhs, const fxp::Fixed rhs)
// {	
// 	if ((double)rhs == 0)
// 		std::cerr << "fxp::Fixed: Error: devision by zero" << std::endl;	
// 	double tmp = lhs / (double)rhs;
// 	fxp::Fixed	res(tmp);
// 	return (tmp);
// }

// bool	fxp::Fixed::operator>(const Fixed& rhs)
// {
// 		return (num_value > rhs.num_value);
// }

// bool	fxp::Fixed::operator<(const Fixed& rhs)
// {
// 		return (num_value < rhs.num_value);
// }

// bool	fxp::Fixed::operator>=(const Fixed& rhs)
// {
// 		return (num_value >= rhs.num_value);
// }

// bool	fxp::Fixed::operator<=(const Fixed& rhs)
// {
// 		return (num_value <= rhs.num_value);
// }

// bool	fxp::Fixed::operator==(const Fixed& rhs)
// {
// 		return (num_value == rhs.num_value);
// }

// bool	fxp::Fixed::operator!=(const Fixed& rhs)
// {
// 		return (num_value != rhs.num_value);
// }


//	MIN-MAX-FUNCTIONS ----------------------------------------------------------------------------
const fxp::Fixed& fxp::Fixed::min(const fxp::Fixed& a, const fxp::Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? b : a );
}

fxp::Fixed& fxp::Fixed::min(fxp::Fixed& a, fxp::Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? b : a );
}

const fxp::Fixed& fxp::Fixed::max(const fxp::Fixed& a, const fxp::Fixed& b)
{
	return (a.getRawBits() >= b.getRawBits() ? a : b );
}

fxp::Fixed& fxp::Fixed::max(fxp::Fixed& a, fxp::Fixed& b)
{
	return (a.getRawBits() >= b.getRawBits() ? a : b );
}