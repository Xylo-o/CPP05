/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:50 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 13:02:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Schrub form", false, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw std::runtime_error("Form is not signed");
	}
	if (executor.getGrade() > getExecGrade()) {
		throw std::runtime_error("Bureaucrat grade too low");
	}
	std::ofstream trees(target + "_shubbery");
	if (!trees) {
		throw std::runtime_error("Failed to create the file");
	}

	trees << "	    oxoxoo    ooxoo\n";
	trees << "  ooxoxo oo  oxoxooo\n";
	trees << " oooo xxoxoo ooo ooox\n";
	trees << " oxo o oxoxo  xoxxoxo\n";
	trees << "  oxo xooxoooo o ooo\n";
	trees << "    ooo\\oo\\  /o/o\n";
	trees << "        \\  \\/ /\n";
	trees << "         |   /\n";
	trees << "         |  |\n";
	trees << "         | D|\n";
	trees << "         |  |\n";
	trees << "         |  |\n";
	trees << "  ______/____\\____\n";

	trees.close();
}