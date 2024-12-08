/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:59:09 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/08 07:43:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"
#include "Colors.hpp"

const char* GradeTooLowException::what() const throw() {
    static std::string msg = std::string(RED) + "Grade is too low!" + NC;
    return msg.c_str();
}