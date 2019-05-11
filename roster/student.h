#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	string getStudentID() const;
	void setStudentID(string ID);

	int getAge() const;
	void setAge(int age);

	string getFirstName() const;
	void setFirstName(string firstName);

	string getLastName() const;
	void setLastName(string lastName);

	string getEmailAddress() const;
	void setEmailAddress(string email);

	string getNumDaysToCompleteEachCourse() const;
	void setNumDaysToCompleteEachCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);

	virtual DegreeType getDegreeProgram() { return DegreeType::NONE; };
	virtual void print();
	
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType);

	~Student();

protected:
	int age;

	int numDaysToComplete[3];

	string studentID;
	string first_name;
	string last_name;
	string email_address;

	DegreeType degreeType;
};