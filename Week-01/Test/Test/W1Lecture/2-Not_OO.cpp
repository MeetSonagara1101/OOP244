#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student
{
	int m_id{};
	char m_name[15]{};
};

void setStudentName(Student* S,int id, const char* name) {
	S->m_id = id;
	strcpy(S->m_name, name);
}

void printStudent(Student* S) {
	cout << "The id of the Student is : " << S->m_id <<endl
		<<"The name of the Student is :" << S->m_name << endl;
}

int main() {

	Student S;
	
	setStudentName(&S, 4, "Mike Larson");
	printStudent(&S);

	return 0;
}