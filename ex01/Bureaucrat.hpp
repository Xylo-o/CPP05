/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:45:36 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 12:53:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
		void signForm(Form& form);
	private:
		const std::string name;		
		int grade;	
};