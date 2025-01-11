/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:57:42 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:34:58 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Colors.hpp"

AForm::AForm(const std::string& name, bool isSigned, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade <= 0 || execGrade <= 0) {
		// throw GradeTooHighException();
		throw std::runtime_error("Grade too high!");
	}
	else if (signGrade > 150 || execGrade <= 0) {
		// throw GradeTooLowException();
		throw std::runtime_error("Grade too low!");
	}
	std::cout << GREEN << "New form " << NC << name << GREEN << " created. The sign grade is: " 
    << NC << signGrade << GREEN << " The execution grade is: " << NC << execGrade << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {
    std::cout << YELLOW << "The form " << NC << name << YELLOW << " has been copied" << NC << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << BLUE << "The form " << NC << name << BLUE << " has been assigned" << NC << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << RED << "The form " << NC << name << RED << " has been destroyed!" << NC << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << BLUE << ", form exec grade " << NC << form.getExecGrade() << BLUE << ", form sign grade " << NC << form.getSignGrade() << BLUE " is signed: " << NC << form.getIsSigned() << std::endl;
    return os;
}

int AForm::getExecGrade() const {
	return execGrade;
}

int AForm::getSignGrade() const {
	return signGrade;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

const std::string& AForm::getName() const {
	return name;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        // throw GradeTooLowException();
		throw std::runtime_error("Grade too low!");
    } else {
        isSigned = true;
    }
}

void AForm::execute(Bureaucrat const & executor) const {}