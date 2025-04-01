#include "Intern.hpp"
#include <map>

Intern::Intern()
{
    std::cout << "Intern has been created." << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern has been copied." << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern assignment operator called." << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern has been destroyed." << std::endl;
}


AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::map<std::string, int> dico;
	dico["robotomy request"] = 0;
	dico["presidential pardon"] = 1;
	dico["shrubbery creation"] = 2;

	if (dico.find(name) == dico.end()){
		throw FormNotFoundException();
	}
	switch (dico[name])
	{
		case 0 : return new RobotomyRequestForm(target);
		case 1 : return new PresidentialPardonForm(target);
		case 2 : return new ShrubberyCreationForm(target);

		default: std::cout << "No form with this name" << std::endl; return NULL;
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found. Valid form types are: 'shrubbery creation', 'robotomy request', and 'presidential pardon'.";
}