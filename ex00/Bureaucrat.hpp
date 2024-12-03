/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:45:36 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/03 19:58:23 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		
		~Bureaucrat();
		std::string getName();
		int getGrade();
		void incrementGrade();
		void decrementGrade();
	private:
		std::string name;		
		int grade;	
};