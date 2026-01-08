#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("default"),
	_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
	: _name(name),
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
	: _name(other._name),
	_signed(other._signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

// Public methods implementation

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}
int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
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
const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << " | signed: " << (form.getSigned() ? "yes" : "no")
	<< " | grade to sign: " << form.getGradeToSign()
	<< " | grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
