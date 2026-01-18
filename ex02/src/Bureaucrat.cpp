#include "../includes/Bureaucrat.hpp"


# include <string>
# include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called for " << _name << " with grade " << _grade << std::endl;
}
// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Public methods implementation

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

// should I put the try-catch here?
void Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm& form)
{
	form.execute(*this);
}

// Getters
std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}
