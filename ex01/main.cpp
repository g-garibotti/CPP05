#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Form Class ---" << std::endl;
    
    try
    {
        std::cout << "\nCreating a form with valid grades:" << std::endl;
        Form valid_form("valid_form", 50, 25);
        std::cout << valid_form << std::endl;
        
        std::cout << "\nCreating bureaucrats with different grades:" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 30);
        Bureaucrat noob("noob", 100);
        
        std::cout << "\n--- Testing Form Signing ---" << std::endl;
        
        std::cout << "\nnoob tries to sign the form:" << std::endl;
        noob.signForm(valid_form);
        std::cout << valid_form << std::endl;
        
        std::cout << "\nManager tries to sign the form:" << std::endl;
        manager.signForm(valid_form);
        std::cout << valid_form << std::endl;
        
        std::cout << "\nManager tries to sign the form again:" << std::endl;
        manager.signForm(valid_form);
        
        std::cout << "\n--- Testing Form Exceptions ---" << std::endl;
        
        std::cout << "\nTrying to create a form with grade 0:" << std::endl;
        Form invalidForm1("Invalid Form", 0, 50);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\nTrying to create a form with grade 151:" << std::endl;
        Form invalidForm2("Invalid Form", 50, 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}