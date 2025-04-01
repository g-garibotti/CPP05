#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Concrete Forms ---" << std::endl;
    
    try {
        std::cout << "\nCreating bureaucrats with different grades:" << std::endl;
        Bureaucrat intern("Intern", 150);
        Bureaucrat lowLevel("LowLevel", 100);
        Bureaucrat executive("Executive", 30);
        Bureaucrat president("President", 5);
        Bureaucrat ceo("CEO", 1);
        
        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        
        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        executive.executeForm(shrubForm);
        
        std::cout << "\nSigning the form:" << std::endl;
        executive.signForm(shrubForm);
        
        std::cout << "\nLow level executing form:" << std::endl;
        lowLevel.executeForm(shrubForm);
        
        std::cout << "\nExecutive executing form:" << std::endl;
        executive.executeForm(shrubForm);
        
        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        RobotomyRequestForm robotomyForm("Marvin");
        
        std::cout << "\nSigning the form:" << std::endl;
        executive.signForm(robotomyForm);
        
        std::cout << "\nLow level executing form:" << std::endl;
        lowLevel.executeForm(robotomyForm);
        
        std::cout << "\nExecutive executing form:" << std::endl;
        executive.executeForm(robotomyForm);
        
        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        PresidentialPardonForm pardonForm("Genaro");
        
        std::cout << "\nSigning the form:" << std::endl;
        president.signForm(pardonForm);
        
        std::cout << "\nExecutive executing form:" << std::endl;
        executive.executeForm(pardonForm);
        
        std::cout << "\nPresident executing form:" << std::endl;
        president.executeForm(pardonForm);
        
        std::cout << "\n--- Testing with different grades ---" << std::endl;
        
        PresidentialPardonForm pardonForm2("Felipe");
        std::cout << "\nCEO signing and executing form:" << std::endl;
        ceo.signForm(pardonForm2);
        ceo.executeForm(pardonForm2);
        
        std::cout << "\nIntern attempting to sign and execute:" << std::endl;
        ShrubberyCreationForm lowForm("home");
        intern.signForm(lowForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}