#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student
{
	int m_id{};
	char m_name[15]{};

	void setStudentName( int id, const char* name) {
		m_id = id;
		strcpy(m_name, name);
	}

	void printStudent() {
		cout << "The id of the Student is : " << m_id << endl
			<< "The name of the Student is :" << m_name << endl;
	}
};



int main() {

	Student S;
	
	S.setStudentName(4, "Mike Larson");
	S.printStudent();

	return 0;
}