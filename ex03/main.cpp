#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main(void) 
{
	Intern i = Intern();
	AForm *f;
	AForm *rf;
	AForm *sf;
	AForm *pf;
	
	std::cout << std::endl << "ROBOTOMY FORM TEST" << std::endl << std::endl;

	try {
		f = i.makeForm("rien", "rien");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		rf =  i.makeForm("robotomy request", "robot");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "SHRUBBERY FORM TEST" << std::endl << std::endl;
	
	try {
		sf =  i.makeForm("shrubbery creation", "berry");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "PRESIDENTIAL FORM TEST" << std::endl << std::endl;
	
	try {
		pf =  i.makeForm("presidential pardon", "president");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	delete rf;
	delete sf;
	delete pf;
	return (0);
}