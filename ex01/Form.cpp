#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
    std::cout << "Form " << _name << " has been created." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    
    std::cout << "Form " << _name << " has been created." << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
    std::cout << "Form " << _name << " has been copied." << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form " << _name << " has been destroyed." << std::endl;
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
    return _gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeRequiredToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high. The highest possible grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low for this form.";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
       << ", Grade required to sign: " << form.getGradeRequiredToSign()
       << ", Grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}