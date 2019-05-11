#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {
public:
	DegreeType getDegreeProgram();
	void print();

	NetworkStudent();

private:
	DegreeType degree;
};