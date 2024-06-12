#include<iostream>
#include "Name.h"
using namespace std;
using namespace seneca;

void createArrayOfObjects() {
	Name N[3];
	
}
int main() {

	int x = 0;
	int y{ 0 };
	int z(0);
	x = z;

	Name N = "Mike Jack", M("Laura", 35), O;

	//N = O;

	//N.setName("Mike");
	N.print();

	//M.setName(" " );
	M.print();
	//O.print();

	cout << "The address of N " << unsigned (&N) << endl;
	cout << "The value of N is " << unsigned(N.returnValue()) << endl;

	cout << "The address of N " << unsigned(&M) << endl;
	cout << "The value of N is " << unsigned(M.returnValue()) << endl;

	N.returnTargetOf().setName("Mike2");

	N.setName("Mike 3");
	N.print();

	N.setName("Mike 6").print();

	Name Q;
	Q.setName("Mike 4", 65).print();

	return 0;

	/*
	- this is a reference to the current object: False
	- this is an address to the current object: True
	- *this is a reference to the current object: True
	*/
}