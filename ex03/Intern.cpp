/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:02:10 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/10 21:30:11 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

Intern::~Intern() {
	std::cout << RED << "The Intern has been fired" << NC << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	AForm form(formName, false, 0, 0);
	const std::string formNames[] = {"shrub", "robot", "presi"}
	
	
	return (form);
}