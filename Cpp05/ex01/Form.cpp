
#include "Form.hpp"

Form::Form() 
	: name("default"), grade_to_sign(1), 
		grade_to_execute(1), is_signed(false) {}

Form::Form(std::string n, int gs, int ge) 
	: name(n), grade_to_sign(gs), 
		grade_to_execute(ge), is_signed(false) {}

Form::Form(const Form& other) 
	: name(other.getName()), grade_to_sign(other.getGradeToSign()), 
		grade_to_execute(other.getGradeToExecute()), is_signed(other.getIsSigned()) {}

Form&	Form::operator=(const Form& lhs)
{
	if (this != &lhs)
		is_signed = lhs.getIsSigned();
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called on form " << name << std::endl;
}

const std::string Form::getName() const 
{
	return name;
}

int	Form::getGradeToSign() const
{
	return grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return grade_to_execute;
}

bool	Form::getIsSigned() const
{
	return is_signed;
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}


std::ostream&	operator<<(std::ostream& os, Form& inst)
{
	os << inst.getName() <<" form:\n" 
		<< "	Grade to sign:		" << inst.getGradeToSign() << "\n"
		<< "	Grade to execute: 	" << inst.getGradeToExecute() << "\n"
		<< "	Signed status:		" << inst.getIsSigned() << std::endl;
	return (os);
}
