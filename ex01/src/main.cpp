#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#include <iostream>

int	main()
{
	std::cout << "=== Test 1: Valid form creation ===" << std::endl;
	try {
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form grade too high (0) ===" << std::endl;
	try {
		Form invalid("Invalid Form", 0, 50);
		std::cout << invalid;
	}
	catch (const Form::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form grade too low (151) ===" << std::endl;
	try {
		Form invalid("Invalid Form", 50, 151);
		std::cout << invalid;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat successfully signs form ===" << std::endl;
	try {
		Form permit("Building Permit", 100, 50);
		Bureaucrat alice("Alice", 50);
		std::cout << "Before signing:" << std::endl;
		std::cout << permit;
		permit.beSigned(alice);
		std::cout << "After signing:" << std::endl;
		std::cout << permit;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat grade too low to sign ===" << std::endl;
	try {
		Form topSecret("Top Secret", 10, 5);
		Bureaucrat bob("Bob", 50);
		std::cout << "Before signing attempt:" << std::endl;
		std::cout << topSecret;
		topSecret.beSigned(bob);
		std::cout << "After signing attempt:" << std::endl;
		std::cout << topSecret;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
