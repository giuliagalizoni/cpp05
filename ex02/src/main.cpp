#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#include <iostream>
#include <ctime>

int	main()
{
	srand(time(NULL));
	try {
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm form("home");

		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
