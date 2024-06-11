/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P1)
Full Name  : Meet Hitesh Sonagara
Student ID#: 122208226
Email      : msonagara@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_

#define DATAFILE "employees.csv"

namespace seneca
{
	struct Employee
	{
		char* m_name;
		int m_empNo;
		double m_salary;
	};
	
	//sorts the dynamic array of employees based on the GPA of the employees.
	void sort();
	
	// loads a employee structure with its values from the file
	bool load();
    
	// allocates the dynamic array of employees and loads all the file 
	//records into the array
   	bool load(Employee&);
	
	// displays a employee record on the screen:
	void display(const Employee&);

	// first sorts the employees then displays all the employees on the screen
	void display();

	// first will deallocate all the names in the employee elements
	// then it will deallocate the employee array 
	void deallocateMemory();
}
#endif // SENECA_EMPLOYEE_H_



