#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	private:
	AForm *makeShrubbery(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makePresidential(std::string target);

	protected:

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// Public methods
		AForm *makeForm(std::string form_name, std::string target);

};

#endif
