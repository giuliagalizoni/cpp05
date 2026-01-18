#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>
#include <ctime>

int	main()
{
	srand(time(NULL));

	// Shrubbery: sign 145, exec 137
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 135);
		ShrubberyCreationForm shrubbery("garden");
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery); // Success
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrubbery2("office");
		intern.signForm(shrubbery2); // Too low to sign
		intern.executeForm(shrubbery2);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Robotomy: sign 72, exec 45
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 50);
		RobotomyRequestForm robotomy("Bender");
		alice.signForm(robotomy);
		alice.executeForm(robotomy); // Too low to execute
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat dave("Dave", 40);
		RobotomyRequestForm robotomy2("Marvin");
		dave.signForm(robotomy2);
		dave.executeForm(robotomy2); // Success
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Presidential: sign 25, exec 5
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat jim("Jim", 30);
		PresidentialPardonForm pardon("Zaphod");
		jim.signForm(pardon); // Too low to sign
		jim.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon2("Arthur");
		boss.signForm(pardon2);
		boss.executeForm(pardon2); // Success
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
