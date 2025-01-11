/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:21 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:27:34 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  public:
    AForm(const std::string& name, bool isSigned, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
	
	const std::string& getName() const;
    bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
  private:
    std::string const name;
    bool isSigned;
    const int signGrade;
    const int execGrade;
};
std::ostream& operator<<(std::ostream& os, const AForm& form);