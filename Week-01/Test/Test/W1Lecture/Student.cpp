#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
using namespace std;

namespace seneca {
	void Student::setStudentName(int id, const char* name) {
		m_id = id;
		strcpy(m_name, name);
	}

	void Student::setStudentName(const char* name) {
		strcpy(m_name, name);
	}

	void Student::printStudent() {
		cout << "The id of the Student is : " << m_id << endl
			<< "The name of the Student is :" << m_name << endl;
	}
}