/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/02 16:34:06 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	// 1. Instanciate Bureaucrat
	Bureaucrat	rui("Rui", 1);

	// 2. Instanciate Intern
	Intern		manel;

	// 3. Valid form
	AForm*	validForm = manel.makeForm("robotomy request", ""); // Dúvida: Não entendi o que é o target, eu digo o que ele significa

	// 4. Invalid form
	AForm*	invalidForm = manel.makeForm("Invalid request", "");

	// 5. Sign and Execute
	rui.signAForm(validForm);
	rui.executeAForm(validForm);

	return (0);
}
