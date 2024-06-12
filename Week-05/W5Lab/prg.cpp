#include <iostream>
#include "MyArray.h"

using namespace std;
using namespace seneca;

void printMyArray(MyArray& MA) {
	for (int i = 0; i < MA.size(); i++)
		cout << MA[i] << " " ;
	cout << endl;
}
int main() {

	//int a[10];
	//a[9] = 20;

	/*for (int i = 0; i <= 10; i++)
		cout << a[i] << endl;*/
	MyArray A=10;
	for (int i = 0; i < 10; i++)
		A[i] = i + 10;

	printMyArray(A);
	return 0;
}