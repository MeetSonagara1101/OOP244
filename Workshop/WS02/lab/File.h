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


#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca
{
	
	bool openFile(const char filename[]);
	void closeFile();
    int noOfRecords();

	// TODO: Declare read prototypes
 	bool read(char*);
	bool read(int&);
	bool read(double& );
}

#endif // !SENECA_FILE_H_