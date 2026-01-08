#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;

	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Public methods
		void beSigned(const Bureaucrat& bureaucrat);

		// Getters and setters
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
