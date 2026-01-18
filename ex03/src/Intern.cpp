#include "Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

#include <iostream>

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& other)
{
	*this = other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

// Destructor
Intern::~Intern() {}

// Public methods implementation
AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_types[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm *form = NULL;
	int index = -1;

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_types[i])
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern cannot create form: " << form_name << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << form_name << std::endl;
	return form;
}
