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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca {

   FILE* fptr;
   bool openFile(const char Filename[]) {
      fptr = fopen(Filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }


	//TODO: read functions go here 

	bool read(char* name) 
	{
		return fscanf(fptr, "%[^\n]\n", name) == 1;
	}


	bool read(int& empNum) 
	{
		return fscanf(fptr, "%d,", &empNum) == 1;
	}

	bool read(double& salary) 
	{
		return fscanf(fptr, "%lf,", &salary) == 1;
	}
}









