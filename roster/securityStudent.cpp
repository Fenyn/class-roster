#include "securityStudent.h"
#include <iostream>

DegreeType SecurityStudent::getDegreeProgram()
{
	return degree;
}

SecurityStudent::SecurityStudent()
{
	degree = DegreeType::SECURITY;
	this->degreeType = DegreeType::SECURITY;
}

void SecurityStudent::print()
{
	cout << '\t' << "First Name: " << first_name;
	cout << '\t' << "Last Name: " << last_name;
	cout << '\t' << "Age: " << age;
	cout << '\t' << "daysInCourse: {" << getNumDaysToCompleteEachCourse() << "}";
	cout << '\t' << "Degree Program: Security";
	cout << endl;
}
