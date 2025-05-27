/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:50:54 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/20 10:51:57 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade())
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& lhs)
{
    if (this != &lhs)
        this->grade = lhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called\n";
}

const std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void    Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char* 	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade cannot exceed 1!");
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade cannot be lower than 150.");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& inst)
{
    os << inst.getName() << ",  bureaucrat grade " << inst.getGrade();
    return (os);
}
