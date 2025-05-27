
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("RobotomyReques", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string t)
	: AForm("RobotomyReques", 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& lhs)
{
	if (this != & lhs)
		AForm::operator=(lhs);
	return *this;
}

void	PresidentialPardonForm::pardon() const
{
	std::cout << target << ", you have been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkRequirments(executor);
	pardon();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "______________________________________________________\n";
	std::cout<<"PresidentialPardonForm destructor called.\n";
	std::cout << "______________________________________________________\n";
}