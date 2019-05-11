#include "softwareStudent.h"
#include <iostream>

DegreeType SoftwareStudent::getDegreeProgram()
{
	return degree;
}

SoftwareStudent::SoftwareStudent()
{
	degree = DegreeType::SOFTWARE;
	this->degreeType = DegreeType::SOFTWARE;
}

void SoftwareStudent::print()
{
	cout << '\t' << "First Name: " << first_name;
	cout << '\t' << "Last Name: " << last_name;
	cout << '\t' << "Age: " << age;
	cout << '\t' << "daysInCourse: {" << getNumDaysToCompleteEachCourse() << "}";
	cout << '\t' << "Degree Program: Software";
}
