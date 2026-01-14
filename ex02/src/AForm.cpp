#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("default"),
	_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute)
	: _name(name),
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& other)
	: _name(other._name),
	_signed(other._signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

// Public methods implementation

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _grade_to_sign;
}
int AForm::getGradeToExecute() const
{
	return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
	{
		_signed = true;
		std::cout << bureaucrat.getName() << " signed " << _name << "." << std::endl;
	}
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because grade is not high enough." << std::endl;
}

//Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm: " << form.getName() << " | signed: " << (form.getSigned() ? "yes" : "no")
	<< " | grade to sign: " << form.getGradeToSign()
	<< " | grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
