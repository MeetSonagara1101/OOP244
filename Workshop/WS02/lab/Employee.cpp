/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Meet Hitesh Sonagara
Student ID#: 122208226
Email      : msonagara@myseneca.ca
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;
namespace seneca {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& emp) {
        bool ok = false;
        char name[128];

        if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
            emp.m_name = new char[strlen(name) + 1];
            strcpy(emp.m_name, name);
            ok = true;
        }
        else {
            ok = false;
        }

        return ok;
   
}
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
      
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          
          for (i = 0; i < noOfEmployees; i++) {
              if (load(employees[i])) {
                  ok = true;
              }
              else 
              {
                  ok = false;
                  cout << "Error: Incorrect number of records read; the data is possibly corrupted." << endl; 
              }
          }
          //close the file
          closeFile();
      }
      else {
          cout << "Could not open data file: " << DATAFILE << endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& emp) {
       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary<<endl;
   }
   void display() {
       sort();
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       for (int i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << "- ";
           display(employees[i]);

       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void  deallocateMemory() {
       int i;
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete[] employees;
       employees = nullptr;

   }
}
