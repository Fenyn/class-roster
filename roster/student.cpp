#include <string>
#include <sstream>
#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;

Student::Student()
{
	studentID = "";
	first_name = "";
	last_name = "";
	email_address = "";
	age = -1;
	numDaysToComplete[0] = -1;
	numDaysToComplete[1] = -1;
	numDaysToComplete[2] = -1;
	degreeType = getDegreeProgram();
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType) {
	this->studentID = studentID;
	this->first_name = firstName;
	this->last_name = lastName;
	this->age = age;
	this->email_address = emailAddress;
	this->numDaysToComplete[0] = daysInCourse1;
	this->numDaysToComplete[1] = daysInCourse2;
	this->numDaysToComplete[2] = daysInCourse3;
	this->degreeType = degreeType;
}

Student::~Student(){
}

string Student::getStudentID() const
{
	return studentID;
}

void Student::setStudentID(string ID)
{
	studentID.assign(ID);
}

int Student::getAge() const
{
	return age;
}

void Student::setAge(int age)
{
	this->age = age;
}

string Student::getFirstName() const
{
	return first_name;
}

void Student::setFirstName(string firstName)
{
	first_name.assign(firstName);
}

string Student::getLastName() const
{
	return last_name;
}

void Student::setLastName(string lastName)
{
	last_name.assign(lastName);
}

string Student::getEmailAddress() const
{
	return email_address;
}

void Student::setEmailAddress(string email)
{
	email_address.assign(email);
}

string Student::getNumDaysToCompleteEachCourse() const
{
	std::stringstream numDaysStringStream;
	numDaysStringStream << numDaysToComplete[0] << "," << numDaysToComplete[1] << "," << numDaysToComplete[2];
	string str(numDaysStringStream.str());
	return str;
}

void Student::setNumDaysToCompleteEachCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
	numDaysToComplete[0] = daysInCourse1;
	numDaysToComplete[1] = daysInCourse2;
	numDaysToComplete[2] = daysInCourse3;
}

//print out basic information for student
void Student::print()
{
	cout << '\t' << "First Name: " << first_name ;
	cout << '\t' << "Last Name: " << last_name;
	cout << '\t' << "Age: " << age;
	cout << '\t' << "daysInCourse: {" << getNumDaysToCompleteEachCourse() << "}";
	cout << " Degree Program: ";

	if (degreeType == DegreeType::SOFTWARE) {
		cout << "Software";
	}
	else if (degreeType == DegreeType::NETWORKING) {
		cout << "Networking";
	}
	else if (degreeType == DegreeType::SECURITY) {
		cout << "Security";
	}
	else {
		cout << "Unknown";
	}

	cout << endl;
}

