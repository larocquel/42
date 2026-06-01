/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:12:26 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 13:43:25 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_value;	// Valor do número de ponto fixo
		static const int	_fBits = 8;	// Número de bits fracionários, sempre = 8 (nesse exercício)

	public:
		// Forma Canônina Ortodoxa
		Fixed(); // Construtor
		Fixed(const Fixed& other);	// Construtor de cópia
		Fixed&	operator=(const Fixed& other);	// Operador de cópia
		~Fixed();	// Destrutor

		// Getter e Setter
		int getRawBits(void) const; // returns the raw value of the fixed-point value.
		void setRawBits(int const raw); // that sets the raw value of the fixed-point number.
};

#endif