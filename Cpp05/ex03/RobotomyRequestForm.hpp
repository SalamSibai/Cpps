
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <cstdlib> 
#include <ctime>

/**
 * @brief 
 *
 * Required grades: sign 72, exec 45
 * Makes some drilling noises. Then, informs that 
 * <target> has been robotomized successfully 50% 
 * of the time. Otherwise, informs that the robotomy failed.
 *
 */
class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        void    makeNoise() const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string t);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& lhs);
        ~RobotomyRequestForm();

		void 	execute(Bureaucrat const & executor) const;
  };

#endif