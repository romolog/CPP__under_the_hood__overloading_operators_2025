/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:04:04 by rponomar          #+#    #+#             */
/*   Updated: 2025/05/06 15:00:21 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace fxp
{
	class Fixed
	{
		public:
			Fixed();
			~Fixed();
			Fixed(const Fixed&);			
			Fixed(const int v);
			Fixed(const double f);
		public:
			operator double();
			operator double() const;
			Fixed&		operator=(const Fixed&);
			Fixed&		operator++();
			Fixed		operator++(int);
			Fixed&		operator--();
			Fixed		operator--(int);

			Fixed&		operator+=(const Fixed&);
			Fixed		operator+(const Fixed&);

			Fixed&		operator-=(const Fixed&);
			Fixed		operator-(const Fixed&);
			
			Fixed&		operator*=(const Fixed&);
			Fixed&		operator/=(const Fixed&);
			bool		operator>(const Fixed&);
			bool		operator<(const Fixed&);
			bool		operator>=(const Fixed&);
			bool		operator<=(const Fixed&);
			bool		operator==(const Fixed&);
			bool		operator!=(const Fixed&);
	
		public:
			int			getRawBits(void) const;
			void		setRawBits(int const raw);
			double		fract_min(void) const;
			int			fract_power(void) const;
		public:
			static const Fixed&		min(const Fixed& a, const Fixed& b);
			static Fixed&			min(Fixed& a, Fixed& b);
			static const Fixed&		max(const Fixed& a, const Fixed& b);
			static Fixed&			max(Fixed& a, Fixed& b);

		private:
			int					num_value;
			static const int	fract_bits = 8;
		private:
			double				ft_operator_double(void) const;
	};
	
	template <typename T> 
		Fixed	operator+(const Fixed lhs, const T rhs);
	template <class T>
		Fixed	operator+(const T lhs, Fixed const rhs);

	template <typename T> 
		Fixed	operator-(const Fixed lhs, const T rhs);
	template <typename T>
		Fixed	operator-(const T lhs, const Fixed rhs);

	// Fixed	operator*(const Fixed lhs, const Fixed rhs);	
	// template <typename T> 
	// 	Fixed	operator*(const Fixed lhs, const T rhs);
	// template <typename T>
	// 	Fixed	operator*(const T lhs, const Fixed rhs);

	// Fixed	operator/(const Fixed lhs, const Fixed rhs);
	// template <typename T> 
	// 	Fixed	operator/(const Fixed lhs, const T rhs);
	// template <typename T>
	// 	Fixed	operator/(const T lhs, const Fixed rhs);	////			
}
