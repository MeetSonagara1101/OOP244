#include <iostream>
#include "Student.h"
using namespace std;
using namespace seneca;

int main() {

	Student S;

	S.setStudentName(4, "Mike Larson");
	S.setStudentName("Smantha Mike");
	S.printStudent();

	return 0;
}