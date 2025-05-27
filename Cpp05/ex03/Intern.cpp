
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& lhs) 
{
    (void)lhs;
    return *this;
}

Intern::~Intern() { std::cout << "Intern destructor called\n"; }

const char* Intern::formDoesntExistException::what() const throw()
{
    return ("Couldn't find form name.");
}

AForm*  Intern::createRobotomyRequestForm(std::string targetName)
{
	return(new RobotomyRequestForm(targetName));
}

AForm*  Intern::createShrubberyCreationForm(std::string targetName)
{
	return(new ShrubberyCreationForm(targetName));
}

AForm*  Intern::createPresidentialPardonForm(std::string targetName)
{
	return(new PresidentialPardonForm(targetName));
}

AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
    AForm *temp;
	std::string arr[] = {"robotomy request", "shrubbery creation", "presidential pardon", form_name};

    int i = 0;
    while (i < 4 && arr[i].compare(form_name.c_str()) != 0)
        i++;

    switch(i)
    {
        case 0: 
            temp = createRobotomyRequestForm(form_target);
            break;
        case 1: 
            temp = createShrubberyCreationForm(form_target);
            break;
        case 2: 
            temp = createPresidentialPardonForm(form_target);
            break;
        case 3:
            throw formDoesntExistException();
    }
	std::cout << "Intern creates " << form_name << std::endl;
	return(temp);
}
