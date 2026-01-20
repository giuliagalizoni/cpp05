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

// Private methods
AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

// Public methods implementation
AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_types[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	AForm* (Intern::*creators[3])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_types[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return  (this->*creators[i])(target);
		}
	}

	std::cout << "Intern cannot create form: " << form_name << std::endl;
	return NULL;
}
