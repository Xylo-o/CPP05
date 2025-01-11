/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:02:10 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 13:00:04 by adprzyby             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

Intern::~Intern() {
	std::cout << RED << "The Intern has been fired" << NC << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	AForm* form = nullptr;
	const std::string formNames[] = {"shrub", "robot", "presi"};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			switch (i)
			{
			case 0:
				form = new ShrubberyCreationForm(formTarget);
				break;
			case 1:
				form = new RobotomyRequestForm(formTarget);
				break;
			case 2:
				form = new PresidentialPardonForm(formTarget);
				break;
			}
			std::cout << GREEN << "Intern creates " << NC << formName << std::endl;
			return form;
		}
	}
	std::cout << RED << "Form name " << NC << formName << RED << " not recognized!" << NC << std::endl; 
	return (nullptr);
}