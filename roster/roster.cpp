#include "roster.h"
#include <sstream>
#include <iostream>

//Add a student to the roster using the specified parameters
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree)
{
	Student* student;
	student = makeStudentWithDegreeType(degree);
	student->setStudentID(studentID);
	student->setFirstName(firstName);
	student->setLastName(lastName);
	student->setEmailAddress(emailAddress);
	student->setAge(age);
	student->setNumDaysToCompleteEachCourse(daysInCourse1, daysInCourse2, daysInCourse3);

	this->classRosterArray->push_back(student);
}

//find student object associated with student ID
//then erase it from the student roster
void Roster::remove(string studentID)
{
	Student* student = getStudentByID(studentID);
	if (student != nullptr) {
		for (int i = 0; i < classRosterArray->size(); i++) {
			if (classRosterArray->at(i) == student) {
				cout << "Removing student ID: " << studentID << endl;
				classRosterArray->at(i)->print();
				cout << endl;
				classRosterArray->erase(classRosterArray->begin() + i);
				break;
			}
		}
	}
	else {
		cout << "Student with id >" << studentID << "< was not found in roster." << endl;
	}
}

//iterate through every student in the roster and call their print() command
void Roster::printAll()
{
	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray->at(i)->print();
		cout << endl;
	}

	cout << endl;
	
}

//return a pointer to the student with associated ID
Student* Roster::getStudentByID(string studentID) {
	Student* student = nullptr;
	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i)->getStudentID() == studentID) {
			student = classRosterArray->at(i);
			break;
		}
	}
	return student;
}

//find student with given ID, then calculate average of its days and display it to console
void Roster::printAverageDaysInCourse(string studentID)
{

	Student* studentToPrint = getStudentByID(studentID);

	vector<string> daysToPrint = getStringElements(studentToPrint->getNumDaysToCompleteEachCourse());
	cout << "Data for studentID: " << studentToPrint->getStudentID() << endl;
	int average = 0;
	for (int i = 0; i < daysToPrint.size(); i++) {
		average += stoi(daysToPrint.at(i));
	}
	average = average / daysToPrint.size();

	cout << '\t' << "Student has spent an average of " << average << " days per course." << endl;
}

//call printAverageDaysInCourse() for each student in roster
void Roster::printAverageDaysInCourseForAllUsers() {
	for (int i = 0; i < classRosterArray->size(); i++) {
		string ID = classRosterArray->at(i)->getStudentID();
		printAverageDaysInCourse(ID);
	}

	cout << endl;
}

//calls email verification method and displays all emails that fail verification
void Roster::printInvalidEmails()
{
	cout << "Printing invalid emails: " << endl;

	for (int i = 0; i < classRosterArray->size(); i++) {
		string studentEmail = classRosterArray->at(i)->getEmailAddress();

		if (emailIsValid(studentEmail) == false) {
			cout << studentEmail << endl;;
		}
	}

	cout << endl;
}

//call print() function for each student with associated degree type
void Roster::printByDegreeProgram(DegreeType degree)
{
	for (int i = 0; i < classRosterArray->size(); i++) {
		DegreeType studentDegree = classRosterArray->at(i)->getDegreeProgram();

		if (degree == studentDegree ) {
			classRosterArray->at(i)->print();
			cout << endl;
		}
	}

	cout << endl;
}

//break down input string into component elements,
//then call add() method using given constructors
void Roster::addStudentUsingInputString(string input){
	
	vector<string> studentInfo = getStringElements(input);

	add(studentInfo.at(0),				//studentID
		studentInfo.at(1),				//first name
		studentInfo.at(2),				//last name
		studentInfo.at(3),				//email address
		stoi(studentInfo.at(4)),		//age
		stoi(studentInfo.at(5)),		//numDaysToCompleteCourse1
		stoi(studentInfo.at(6)),		//numDaysToCompleteCourse2
		stoi(studentInfo.at(7)),		//numDaysToCompleteCourse3
		getDegreeFromStudentInput(input) //degree type
	);

}

//subdivide a string into a string vector using comma delimiter
vector<string> Roster::getStringElements(string input)
{
	stringstream inputSS(input);
	vector<string> elementsOfString;
	while (inputSS.good()) {
		string studentElement;
		getline(inputSS, studentElement, ',');
		elementsOfString.push_back(studentElement);
	}

	return elementsOfString;
}

//returns DegreeType based off of string input
DegreeType Roster::getDegreeFromStudentInput(string input)
{
	DegreeType degree;
	degree = DegreeType::NONE;
	if (input.find("SECURITY") != string::npos) {
		degree = DegreeType::SECURITY;
	}
	else if (input.find("NETWORK") != string::npos) {
		degree = DegreeType::NETWORKING;
	}
	else if (input.find("SOFTWARE") != string::npos) {
		degree = DegreeType::SOFTWARE;
	}
	return degree;
}

//allocate memory for a student subclass based off degree type,
//then return pointer to its address
Student* Roster::makeStudentWithDegreeType(DegreeType degreeType)
{
	if (degreeType == DegreeType::SOFTWARE) {
		return new SoftwareStudent();
	}
	else if (degreeType == DegreeType::NETWORKING) {
		return new NetworkStudent();
	}
	else if (degreeType == DegreeType::SECURITY) {
		return new SecurityStudent();
	}

	return nullptr;
}

//uses regex strings to validate if email conforms to following criteria:
//		* string contains an @ symbol
//		* string contains a . symbol following the @
//		* string does not have any spaces
//returns true if all three criteria are met, false if otherwise
bool Roster::emailIsValid(string emailAddress)
{
	bool isValid = true;

	size_t at = emailAddress.find('@');
	if (at == string::npos) {
		isValid = false;
	}

	size_t period = emailAddress.find('.', at + 1);
	if (period == string::npos) {
		isValid = false;
	}

	size_t space = emailAddress.find(" ");
	if (space != string::npos) {
		isValid = false;
	}

	return isValid;
}

//constructor
Roster::Roster() {
	classRosterArray->clear();
}

int main() {
	Roster classRoster;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Anthony,Knight,aknig76@wgu.edu,29,10,15,13,SOFTWARE" };

	cout << "************************ BEGIN PROGRAM ************************" << endl;
	cout << "Course Title: Scripting and Programming - Applications C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Name: Anthony Knight" << endl;
	cout << "Student ID: 001070581" << endl << endl;

	for (int i = 0; i < 5; i++) {
		classRoster.addStudentUsingInputString(studentData[i]);
	}
	
	cout << "************** Printing all *************" << endl;
	classRoster.printAll();

	cout << "************* Printing average days in course *************" << endl;
	classRoster.printAverageDaysInCourseForAllUsers();

	cout << "************* Printing invalid emails *************" << endl;
	classRoster.printInvalidEmails();

	cout << "************* Printing Software Degrees *************" << endl;
	classRoster.printByDegreeProgram(DegreeType::SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
}
