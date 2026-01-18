#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137 ), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137 ), _target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	_target = other._target;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Private methods implementation
void ShrubberyCreationForm::performAction(Bureaucrat const & executor) const
{
	std::ofstream outfile;
	std::string filename = _target + "_shrubbery";
	outfile.open(filename.c_str());
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
