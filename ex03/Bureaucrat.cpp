/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:55:09 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 18:22:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
	if (grade <= 0) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
		throw GradeTooHighException();
    }
    grade--;
    std::cout << name << CYAN << "'s grade incremented to " << NC << grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
		throw GradeTooLowException();
    }
    grade++;
    std::cout << name << MAGENTA << "'s grade decremented to " << NC << grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << BLUE << ", bureaucrat grade " << NC << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << GREEN << " signed " << NC << form.getName() << std::endl;
	}
    catch (const std::exception& e) {
        std::cout << name << RED << " couldn't sign " << NC << form.getName() << RED << " because " << NC << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << name << BLUE << " executed " << NC << form.getName() << std::endl; 
	} catch (const std::exception& e) {
		std::cout << name << RED << " couldn't execute the form " << NC << form.getName() << RED << " because " << NC << e.what() << std::endl;
	}
}