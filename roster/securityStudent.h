#include "student.h"
#include "degree.h"

class SecurityStudent : public Student {
public:
	DegreeType getDegreeProgram();
	void print();

	SecurityStudent();

private:
	DegreeType degree;
};