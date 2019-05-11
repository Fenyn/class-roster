#include "networkStudent.h"
#include <iostream>

DegreeType NetworkStudent::getDegreeProgram()
{
	return degree;
}

NetworkStudent::NetworkStudent()
{
	degree = DegreeType::NETWORKING;
	this->degreeType = DegreeType::NETWORKING;
}

void NetworkStudent::print()
{
	cout << '\t' << "First Name: " << first_name;
	cout << '\t' << "Last Name: " << last_name;
	cout << '\t' << "Age: " << age;
	cout << '\t' << "daysInCourse: {" << getNumDaysToCompleteEachCourse() << "}";
	cout << '\t' << "Degree Program: Network";
}
