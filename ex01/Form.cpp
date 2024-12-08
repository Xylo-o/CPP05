/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:49:52 by kali              #+#    #+#             */
/*   Updated: 2024/12/08 09:27:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"
#include <iostream>
#include <string>
#include <exception>

Form::Form(const std::string& name, bool isSigned, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
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

void Form::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    } else {
        isSigned = true;
    }
}