#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}
// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	_target = other._target;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Private methods implementation
void RobotomyRequestForm::performAction(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " tries to execute form" << this->getName() << std::endl;
	std::cout << "Buzzzssfihfifdofiigoitttrrrrrrr" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been succssfully robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
