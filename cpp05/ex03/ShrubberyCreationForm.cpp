#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	
	_target = "none";
	
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", _sign, _exec), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor with parameters called" << std::endl;
	
	return ;
}	

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	
	*this = src;
	
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	
	return ;
}
		
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	
	this->_target = src._target;
	
	return *this;
}

char tree[] =  "                                  .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                   :         ;                   :;%;'     ., \n"  
"           ,.        %;     %;            ;        %;'    ,;\n"
"            ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"             %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'\n" 
"                        `@%.  `;@%.      ;@@%;\n"    
"                          `@%%. `@%%    ;@@%;\n" 
"                            ;@%. :@%%  %@@%;\n"
"                              %@bd%%%bd%%:;\n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '\n"         
"                                %@@@o%;:(.,'\n"      
"                            `.. %@@@o%::;\n"  
"                               `)@@@o%::;\n" 
"                                %@@(o)::;\n"
"                               .%@@@@%::;\n"
"                               ;%@@@@%::;.\n" 
"                              ;%@@@@%%:;;;.\n"
"                          ...;%@@@@@%%:;;;;,..\n";


void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);
	
	std::ofstream outFile(this->_target + "_shrubbery");
	
	if (!outFile.is_open())
	{
		std::cerr << "Error: File not opened" << std::endl;
		return ;
	}
	outFile << tree << std::endl;
	outFile.close();
	
	return ;
}