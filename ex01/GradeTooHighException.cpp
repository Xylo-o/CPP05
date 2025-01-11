/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:59:01 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/11 16:34:14 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"
#include "Colors.hpp"

const char* GradeTooHighException::what() const throw() {
    static std::string msg = std::string(RED) + "Grade is too high!" + NC;
    return msg.c_str();
}