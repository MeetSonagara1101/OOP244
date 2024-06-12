#include <iostream>
#include "Container.h"

using namespace std;
using namespace seneca;

int main() {

	Container C;
	C.print();

	C.addTo(50).print();

	C += 50;//C = C+ 50;
	C.print();

	cout <<"Using the getter function: "<< C.getContent() << endl;

	int value = 30;
	int total;

	total = value += C; //value = value + C;
	C.print();
	cout << "THe total is: " << total << endl;

	cout << (int)C << endl;
	cout << (double)C << endl;

	Container D(100, 50), E;
	E = D + C;
	E.print();

	return 0;
}