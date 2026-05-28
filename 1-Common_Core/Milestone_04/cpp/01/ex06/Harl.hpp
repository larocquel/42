/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 00:34:51 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/28 01:59:16 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.cpp

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        Harl();
        ~Harl();
        void    filter(std::string level);
};

#endif
