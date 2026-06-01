/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:38:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 19:53:49 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>	// roundf()

class	Fixed
{
	private:
		int	_value;
		static const int	_fBits = 8;

	public:
		Fixed(const int n);
		Fixed(const float n);	// Como posso ter dois construtores e fazer a ortodox canonical form?

};

#endif