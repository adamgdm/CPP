#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: Form("ShrubberyCreationForm", 145, 137)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 145 || getReqExecGrade() > 137)
		throw Form::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 145 || getReqExecGrade() > 137)
		throw Form::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) 
	: Form(copy)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string name;

    name = this->target + "_shrubbery";

    if (!this->isFormSigned())
        throw Form::FormIsNotSignedException();
    if (executor.getGrade() > this->getReqExecGrade())
        throw Form::GradeTooLowException();

    std::ofstream Myfile(name);

    Myfile << "                                                         .\n"
              "                                              .         ;  \n"
              "                 .              .              ;%     ;;   \n"
              "                   ,           ,                :;%  %;   \n"
              "                    :         ;                   :;%;'     .,   \n"
              "           ,.        %;     %;            ;        %;'    ,;\n"
              "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
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
              "                                #@%%%%%:;;\n"
              "                                %@@%%%::;\n"
              "                                %@@@%(o);  . '         \n"
              "                                %@@@o%;:(.,'         \n"
              "                            `.. %@@@o%::;         \n"
              "                               `)@@@o%::;         \n"
              "                                %@@(o)::;        \n"
              "                               .%@@@@%::;         \n"
              "                               ;%@@@@%::;.          \n"
              "                              ;%@@@@%%:;;;. \n"
              "                          ...;%@@@@@%%:;;;;,.." << std::endl;
}