/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:44 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 12:58:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy form", false, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED << "Robotomy " << NC << getName() << RED << "has been destroyed!" << NC << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw std::runtime_error("The form is not signed");
	}
	if (executor.getGrade() > getExecGrade()) {
		throw std::runtime_error("Bureaucrat grade too low");
	}
	
	std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);

    std::cout << YELLOW << "BzzzzZZzz..   SUTUTUTUTU.. BrrrRRRrrrRRrrr..." << NC << std::endl;
	if (d(gen)) {
        std::cout << GREEN << target << " has been robotomied successfully!" << NC << std::endl;
    } else {
        std::cout << RED << "The robotomy failed on " << target << "!" << NC << std::endl;
    }
}