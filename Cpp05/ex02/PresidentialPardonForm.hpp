

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        void    pardon() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string t);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& lhs);
        ~PresidentialPardonForm();

		void 	execute(Bureaucrat const & executor) const;
};


#endif