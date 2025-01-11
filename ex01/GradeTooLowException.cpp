/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:59:09 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:34:36 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"
#include "Colors.hpp"

const char* GradeTooLowException::what() const throw() {
    static std::string msg = std::string(RED) + "Grade is too low!" + NC;
    return msg.c_str();
}