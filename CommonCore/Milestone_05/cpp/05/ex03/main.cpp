/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/02 16:58:51 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main()
{
	// 1. Instanciate Bureaucrat
	Bureaucrat	rui("Rui", 1);

	// 2. Instanciate Intern
	Intern		manel;

	// 3. Valid form
	AForm*	validForm = manel.makeForm("robotomy request", "Marvin");

	// 4. Invalid form
	AForm*	invalidForm = manel.makeForm("Invalid request", "Wall-E");

	// 5. Sign and Execute
	if (validForm != NULL)
	{
		rui.signAForm(*validForm);
		rui.executeAForm(*validForm);
	}

	delete validForm;
	delete invalidForm;

	return (0);
}
