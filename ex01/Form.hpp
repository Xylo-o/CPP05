/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:49:55 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:31:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  public:
    Form(const std::string& name, bool isSigned, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
	
	const std::string& getName() const;
    bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
    void beSigned(Bureaucrat bureaucrat);
  private:
    std::string const name;
    bool isSigned;
    const int signGrade;
    const int execGrade;
};
std::ostream& operator<<(std::ostream& os, const Form& form);