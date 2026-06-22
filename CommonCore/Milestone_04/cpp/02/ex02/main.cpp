/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 18:23:56 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main(void)
// {
//     std::cout << "\n=======================================" << std::endl;
//     std::cout << "         FIXED CLASS TEST TABLE          " << std::endl;
//     std::cout << "=======================================\n" << std::endl;

//     std::cout << "--- 1. INITIALIZATION ---" << std::endl;
//     Fixed a(10);
//     Fixed b(5.5f);
//     Fixed c(a);
//     Fixed d;
//     d = b;

//     std::cout << "a (Int 10): " << a << std::endl;
//     std::cout << "b (Float 5.5): " << b << std::endl;
//     std::cout << "c (Copy of a): " << c << std::endl;
//     std::cout << "d (Assigned from b): " << d << std::endl;

//     std::cout << "\n--- 2. ARITHMETIC OPERATORS ---" << std::endl;
//     std::cout << "a + b = " << a + b << std::endl;
//     std::cout << "a - b = " << a - b << std::endl;
//     std::cout << "a * b = " << a * b << std::endl;
//     std::cout << "a / b = " << a / b << std::endl;

//     std::cout << "\n--- 3. COMPARISON OPERATORS ---" << std::endl;
//     std::cout << "Is a > b?  " << (a > b ? "True" : "False") << std::endl;
//     std::cout << "Is a < b?  " << (a < b ? "True" : "False") << std::endl;
//     std::cout << "Is a >= c? " << (a >= c ? "True" : "False") << std::endl;
//     std::cout << "Is a <= c? " << (a <= c ? "True" : "False") << std::endl;
//     std::cout << "Is a == c? " << (a == c ? "True" : "False") << std::endl;
//     std::cout << "Is a != b? " << (a != b ? "True" : "False") << std::endl;

//     std::cout << "\n--- 4. INCREMENT / DECREMENT ---" << std::endl;
//     Fixed e;
//     std::cout << "Starting 'e' at: " << e << std::endl;
//     std::cout << "Pre-increment (++e): " << ++e << std::endl;
//     std::cout << "Current 'e': " << e << std::endl;
//     std::cout << "Post-increment (e++): " << e++ << std::endl;
//     std::cout << "Current 'e': " << e << std::endl;
//     std::cout << "Pre-decrement (--e): " << --e << std::endl;
// 	std::cout << "Current 'e': " << e << std::endl;
//     std::cout << "Post-decrement (e--): " << e-- << std::endl;
//     std::cout << "Final 'e': " << e << std::endl;

//     std::cout << "\n--- 5. MIN / MAX FUNCTIONS ---" << std::endl;
//     std::cout << "Min of a (10) and b (5.5): " << Fixed::min(a, b) << std::endl;
//     std::cout << "Max of a (10) and b (5.5): " << Fixed::max(a, b) << std::endl;

//     // Testing with const objects
//     std::cout << "\n--- CONST MIN / MAX ---" << std::endl;
//     const Fixed const_a(100.1f);
//     const Fixed const_b(200.2f);
// 	std::cout << "const_a (Float 100.1): " << const_a << std::endl;
//     std::cout << "const_b (Float 200.2): " << const_b << std::endl;
//     std::cout << "Min of const_a and const_b: " << Fixed::min(const_a, const_b) << std::endl;
//     std::cout << "Max of const_a and const_b: " << Fixed::max(const_a, const_b) << std::endl;

//     std::cout << "\n=======================================\n" << std::endl;

//     return 0;
// }