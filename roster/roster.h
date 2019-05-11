#include <string>
#include <vector>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "degree.h"

using namespace std;

class Roster{
public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree);
	void addStudentUsingInputString(string input);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printAverageDaysInCourseForAllUsers();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeType degree);
	//Roster(string* rosterInput);
	Roster();

private:
	vector<Student*> classRosterArray[1];
	vector<string> getStringElements(string input);
	DegreeType getDegreeFromStudentInput(string input);
	Student* makeStudentWithDegreeType(DegreeType degreeType);

	bool emailIsValid(string emailAddress);
	Student* getStudentByID(string studentID);


}
;
