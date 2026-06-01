/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:12:26 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 17:52:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 _value;       // Fixed-point number value
        static const int    _fBits = 8;   // Number of fractional bits

    public:
        // Orthodox Canonical Form
        Fixed();                                  // Default constructor
        Fixed(const Fixed& other);                // Copy constructor
        Fixed& operator=(const Fixed& other);     // Copy assignment operator
        ~Fixed();                                 // Destructor

        // Getters and Setters
        int     getRawBits(void) const;           // Returns the raw value
        void    setRawBits(int const raw);        // Sets the raw value
};

#endif