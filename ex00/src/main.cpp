#include "../includes/Bureaucrat.hpp"

#include <iostream>

int	main()
{
	std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
	try {
		Bureaucrat invalid("TooHigh", 0);
		std::cout << invalid;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("TooLow", 151);
		std::cout << invalid;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 2);
		std::cout << alice;
		alice.incrementGrade();
		std::cout << "After increment: " << alice;
		alice.incrementGrade(); // Should throw
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << charlie;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie;
		charlie.decrementGrade(); // Should throw
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
