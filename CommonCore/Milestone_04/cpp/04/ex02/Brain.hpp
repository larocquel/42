/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:52:58 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 10:52:59 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Brain.hpp

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();

		void				setIdea(int index, const std::string& ideas);
		const std::string&	getIdea(int index) const;
};

#endif