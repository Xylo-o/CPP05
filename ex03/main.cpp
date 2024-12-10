/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/10 20:09:03 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm presi("Ford Prefect");

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << presi << std::endl;

        alice.signForm(shrub);
        alice.signForm(robotomy);
        alice.signForm(presi);

        bob.signForm(shrub);
        bob.signForm(robotomy);
        bob.signForm(presi);

        std::cout << shrub << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << presi << std::endl;

        alice.executeForm(shrub);
        alice.executeForm(robotomy);
        alice.executeForm(presi);

        bob.executeForm(shrub);
        bob.executeForm(robotomy);
        bob.executeForm(presi);

        try {
            Bureaucrat invalidHigh("InvalidHigh", 0);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Bureaucrat invalidLow("InvalidLow", 200);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        ShrubberyCreationForm unsignedForm("Park");
        bob.executeForm(unsignedForm);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return 0;
}