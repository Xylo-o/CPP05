/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:22 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 18:37:36 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm presi("Ford Prefect");

        std::cout << MAGENTA << "================ SIGNING FORMS ================" << NC << std::endl;
        alice.signForm(shrub);
        alice.signForm(robotomy);
        alice.signForm(presi);

        bob.signForm(shrub);
        bob.signForm(robotomy);
        bob.signForm(presi);

        std::cout << MAGENTA << "=============== EXECUTING FORMS ===============" << NC << std::endl;
        alice.executeForm(shrub);
        alice.executeForm(robotomy);
        alice.executeForm(presi);

        bob.executeForm(shrub);
        bob.executeForm(robotomy);
        bob.executeForm(presi);

        std::cout << MAGENTA << "=============== EXCEPTION TESTS ===============" << NC << std::endl;
        try {
            Bureaucrat invalid("Invalid", 151);
        } catch (const std::exception &e) {
            std::cerr << RED << e.what() << NC << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << RED << e.what() << NC << std::endl;
    }
    return 0;
}