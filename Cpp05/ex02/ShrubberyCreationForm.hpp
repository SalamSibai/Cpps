/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:50:31 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 16:18:46 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

/**
 * @brief 
 *
 * Required grades: sign 145, exec 137
 * Creates a file <target>_shrubbery in the working
 * directory and writes ASCII trees inside it.
 *
 */
class ShrubberyCreationForm : public AForm
{
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string n, int gs, int ge);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& lhs);
};

#endif