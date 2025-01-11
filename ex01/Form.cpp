/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:49:52 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:34:06 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

Form::Form(const std::string& name, bool isSigned, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade <= 0 || execGrade <= 0) {
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || execGrade <= 0) {
		throw GradeTooLowException();
	}
	std::cout << GREEN << "New form " << NC << name << GREEN << " created. The sign grade is: " 
    << NC << signGrade << GREEN << " The execution grade is: " << NC << execGrade << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {
    std::cout << YELLOW << "The form " << NC << name << YELLOW << " has been copied" << NC << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << BLUE << "The form " << NC << name << BLUE << " has been assigned" << NC << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << RED << "The form " << NC << name << RED << " has been destroyed!" << NC << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << BLUE << ", form exec grade " << NC << form.getExecGrade() << BLUE << ", form sign grade " << NC << form.getSignGrade() << BLUE " is signed: " << NC << form.getIsSigned() << std::endl;
    return os;
}

int Form::getExecGrade() const {
	return execGrade;
}

int Form::getSignGrade() const {
	return signGrade;
}

bool Form::getIsSigned() const {
	return isSigned;
}

const std::string& Form::getName() const {
	return name;
}

void Form::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    } else {
        isSigned = true;
    }
}