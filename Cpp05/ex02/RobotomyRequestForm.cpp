
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyReques", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string t)
	: AForm("RobotomyReques", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& lhs)
{
	if (this != & lhs)
		AForm::operator=(lhs);
	return *this;
}

void	RobotomyRequestForm::makeNoise() const
{
	std::cout << "drilling noises...." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << target << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkRequirments(executor);
	makeNoise();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "______________________________________________________\n";
	std::cout<<"RobotomyRequestForm destructor called.\n";
	std::cout << "______________________________________________________\n";
}