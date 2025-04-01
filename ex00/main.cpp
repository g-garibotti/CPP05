#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Bureaucrat Class ---" << std::endl;
    
    try
    {
        std::cout << "\nCreating a bureaucrat with grade 75:" << std::endl;
        Bureaucrat normal("Normal", 75);
        std::cout << normal << std::endl;
        
        std::cout << "\nIncrementing grade:" << std::endl;
        normal.incrementGrade();
        std::cout << normal << std::endl;
        
        std::cout << "\nDecrementing grade:" << std::endl;
        normal.decrementGrade();
        std::cout << normal << std::endl;
        
        std::cout << "\nTrying to create a bureaucrat with grade 0:" << std::endl;
        Bureaucrat tooHigh("tooHigh", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\nTrying to create a bureaucrat with grade 151:" << std::endl;
        Bureaucrat tooLow("Brown", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\nTrying to increment grade 1:" << std::endl;
        Bureaucrat Boss("Boss", 1);
        std::cout << Boss << std::endl;
        Boss.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\nTrying to decrement grade 150:" << std::endl;
        Bureaucrat lowest("Intern", 150);
        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}