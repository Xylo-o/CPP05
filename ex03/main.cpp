/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/10 18:25:38 by adprzyby         ###   ########.fr       */
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

        bob.signForm(shrub); // Should fail due to low grade
        bob.signForm(robotomy); // Should fail due to low grade
        bob.signForm(presi); // Should fail due to low grade

        std::cout << shrub << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << presi << std::endl;

        // Test 2: Executing forms
        alice.executeForm(shrub);
        alice.executeForm(robotomy);
        alice.executeForm(presi);

        bob.executeForm(shrub); // Should fail due to low grade
        bob.executeForm(robotomy); // Should fail due to low grade
        bob.executeForm(presi); // Should fail due to low grade

        // Test 3: Handling exceptions for invalid grades
        try {
            Bureaucrat invalidHigh("InvalidHigh", 0); // Should throw exception
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Bureaucrat invalidLow("InvalidLow", 200); // Should throw exception
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test 4: Handling exceptions for unsigned forms
        ShrubberyCreationForm unsignedForm("Park");
        bob.executeForm(unsignedForm); // Should throw exception because form is not signed
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return 0;
}