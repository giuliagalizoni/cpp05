#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(time(NULL));
	Intern intern;

	std::cout << "=== Test 1: Valid Forms ===" << std::endl;
	AForm* form1 = intern.makeForm("Shrubbery Creation", "home");
	AForm* form2 = intern.makeForm("Robotomy Request", "Bender");
	AForm* form3 = intern.makeForm("Presidential Pardon", "Arthur");

	std::cout << "\n=== Test 2: Invalid Form ===" << std::endl;
	intern.makeForm("invalid form", "target");

	std::cout << "\n=== Test 3: Execute Created Forms ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
		}
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
		}
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Clean up
	delete form1;
	delete form2;
	delete form3;

	return 0;
}
