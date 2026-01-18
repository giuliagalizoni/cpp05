#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {}

// Copy constructor;
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	_target  = other._target;
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Private methods implementation
void PresidentialPardonForm::performAction(Bureaucrat const & executor) const
{
	std::cout << _target << " has been pardoned by " << executor.getName() << std::endl;
}
