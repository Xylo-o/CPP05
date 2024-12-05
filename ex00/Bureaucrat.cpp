/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:41:47 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 17:38:02 by adprzyby         ###   ########.fr       */
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
	std::cout << "Bureaucrat " << name << " has been emloyed with a grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat " << name << " has multiplied" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	std::cout << "Bureaucrat " << name << " has been assigned" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << name << " has been sent packing!" << std::endl;
}

int Bureaucrat::getGrade() {
	return grade;
}

const std::string& Bureaucrat::getName() {
	return name;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	grade--;
	std::cout << "Bureaucrat's"
}

void Bureaucrat::decrementGrade() {
	
}