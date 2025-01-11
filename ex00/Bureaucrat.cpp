/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:41:47 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:30:08 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
	if (grade <= 0) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	std::cout << GREEN << "Bureaucrat " << NC << name << GREEN << " has been emloyed with a grade: " << NC << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){
	std::cout << YELLOW << "Bureaucrat " << NC << name << YELLOW << " has multiplied" << NC << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	std::cout << BLUE << "Bureaucrat " << NC << name << BLUE << " has been assigned" << NC << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat " << NC << name << RED << " has been sent packing!" << NC << std::endl;
}

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