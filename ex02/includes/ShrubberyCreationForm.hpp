#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		// Public methods
		void execute (Bureaucrat const & executor);

		// Exceptions
		class OpenFileException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

};

#endif
