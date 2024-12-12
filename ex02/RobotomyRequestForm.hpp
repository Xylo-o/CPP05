/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:47 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/12 12:58:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <random>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		
		void execute(Bureaucrat const & executor) const;
	private:
		const std::string target;
};