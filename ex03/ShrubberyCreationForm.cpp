#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm has been destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecutability(executor);

    std::string fileName = _target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());
    
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }
    
    outFile << "        /\\        " << std::endl;
    outFile << "       /  \\       " << std::endl;
    outFile << "      /    \\      " << std::endl;
    outFile << "     /      \\     " << std::endl;
    outFile << "    /        \\    " << std::endl;
    outFile << "   /__________\\   " << std::endl;
    outFile << "        ||        " << std::endl;
    outFile << "        ||        " << std::endl;
    outFile << "        ||        " << std::endl;
    
    outFile.close();
    
    std::cout << "Created shrubbery file: " << fileName << std::endl;
}