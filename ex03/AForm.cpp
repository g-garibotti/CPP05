#include "AForm.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
    std::cout << "AForm " << _name << " has been created." << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    
    std::cout << "AForm " << _name << " has been created." << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
    std::cout << "AForm " << _name << " has been copied." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " has been destroyed." << std::endl;
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
    return _gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeRequiredToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::checkExecutability(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeRequiredToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high. The highest possible grade is 1.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low for this form.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
       << ", Grade required to sign: " << form.getGradeRequiredToSign()
       << ", Grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}