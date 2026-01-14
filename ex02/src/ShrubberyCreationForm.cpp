#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137 )
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137 ), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;

}


// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	_target = other._target;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Public methods implementation
void ShrubberyCreationForm::execute (Bureaucrat const & executor)
{
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile;
	outfile.open((_target.append("_shrubbery").c_str()));
	if (!outfile.is_open()) {
		throw OpenFileException();
	}
	outfile << "         Shrubbery Tree                                 .\n"
              "                                              .         ;  \n"
              "                 .              .              ;%     ;;   \n"
              "                   ,           ,                :;%  %;   \n"
              "                    :         ;                   :;%;'     .,   \n"
              "           ,.        %;     %;            ;        %;'    ,;  \n"
              "             ;       ;%;  %%;        ,     %;    ;%;    ,%' \n"
              "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
              "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
              "                `%;.     ;%;     %;'         `;%%;.%;'\n"
              "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
              "                    `:%;.  :;bd%;          %;@%;'\n"
              "                      `@%:.  :;%.         ;@@%;'   \n"
              "                        `@%.  `;@%.      ;@@%;         \n"
              "                          `@%%. `@%%    ;@@%;        \n"
              "                            ;@%. :@%%  %@@%;       \n"
              "                              %@bd%%%bd%%:;     \n"
              "                                #@%%%%%:;;;\n"
              "                                %@@%%%::;;\n"
              "                                %@@@%(o);  . '         \n"
              "                                %@@@o%;:(.,'         \n"
              "                            `.. %@@@o%::;         \n"
              "                               `)@@@o%::;         \n"
              "                                %@@(o)::;        \n"
              "                               .%@@@@%::;         \n"
              "                               ;%@@@@%::;.          \n"
              "                              ;%@@@@%%:;;;. \n"
              "                          ...;%@@@@@%%:;;;;,..\n";
	std::cout << "ShrubberyCreationForm was executed by " << executor.getName() << std::endl;
	outfile.close();

}

const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
	return "Could not open file";
}
