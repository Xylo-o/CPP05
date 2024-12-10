/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:38 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/10 18:05:28 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presi form", false, 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED << "Presi " << NC << getName() << RED << "has been destroyed!" << NC << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw std::runtime_error("Form is not signed");
	}
	if (executor.getGrade() > getExecGrade()) {
		throw std::runtime_error("Bureaucrat grade too low");
	}
	std::cout << target << GREEN << " has been pardoned by Zaphod Beeblebrox" << NC << std::endl;
}