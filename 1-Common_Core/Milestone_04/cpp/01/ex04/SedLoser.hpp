/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 03:36:23 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/29 19:09:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDLOSER_HPP
# define SEDLOSER_HPP

# include <iostream>
# include <fstream>
# include <string>

// Class: Handles the file reading and string replacement logic
class	SedLoser
{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;

	public:
		SedLoser(std::string filename, std::string s1, std::string s2);
		~SedLoser();
		bool	replace(void);
};

#endif