/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:59:01 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/08 07:44:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"
#include "Colors.hpp"

const char* GradeTooHighException::what() const throw() {
    static std::string msg = std::string(RED) + "Grade is too high!" + NC;
    return msg.c_str();
}