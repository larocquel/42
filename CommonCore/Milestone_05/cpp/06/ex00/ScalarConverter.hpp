/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:11:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/08/06 03:20:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.hpp

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>	// std::isdigit, std::isprint
#include <limits>	// infinity(), quiet_NaN()
#include <cstdlib>	// strtod()
#include <cmath>	// std::floor()
#include <climits>	// INT_MAX, INT_MIN, CHAR_MAX, CHAR_MIN
#include <iomanip>	// setprecision()

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void	convert(const std::string& literal);
};

#endif