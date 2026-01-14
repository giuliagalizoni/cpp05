#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}
// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	_target = other._target;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Public methods implementation
void RobotomyRequestForm::execute (Bureaucrat const & executor)
{
		std::cout << "Buzzzssfihfifdofiigoitttrrrrrrr" << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been succssfully robotomized." << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;

}
