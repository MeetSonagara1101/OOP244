
#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include <iostream>

namespace seneca {
	struct Student
	{
	private:
		int m_id{};
		char m_name[15]{};

	public:
		void setStudentName(int id, const char* name);
		void setStudentName(const char* name);
		void printStudent();
		
	};

}

#endif // !SENECA_STUDENT_H
