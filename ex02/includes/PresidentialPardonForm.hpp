#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string _target;
	void performAction(Bureaucrat const & executor) const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif
