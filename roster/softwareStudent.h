#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {
public:
	DegreeType getDegreeProgram();
	void print();

	SoftwareStudent();

private:
	DegreeType degree;
};