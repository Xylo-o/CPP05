/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/09 20:55:23 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int main() {
	try {
		Form f1("f1", false, 170, 170);
	}  catch (const std::exception& e) {
		std::cerr << "Form exception: " << e.what() << std::endl;
	}
	try {
		Form f2("f2", false, 0, 0);
	}  catch (const std::exception& e) {
		std::cerr << "Form exception: " << e.what() << std::endl;
	}
	
	try {
		Form f3("f3", false, 120, 120);
		Form f4("f4", false, 50, 50);
		Bureaucrat alice("Alice", 51);
		std::cout << alice << std::endl;
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;
		alice.signForm(f3);
		alice.signForm(f4);
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;

		alice.incrementGrade();
		alice.signForm(f4);
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return 0;
}