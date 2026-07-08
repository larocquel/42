/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:11:17 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/08 23:11:40 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.hpp

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConveter& other);
		~ScalarConverter();

	public:
		// Static Method
		static void	convert(const std::string& literal);
};

#endif