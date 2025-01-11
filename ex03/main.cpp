/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:22 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 13:00:43 by adprzyby             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("shrub", "home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("robot", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("presi", "Zaphod Beeblebrox");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("unknown", "target");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    return 0;
}