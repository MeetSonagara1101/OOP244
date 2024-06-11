#include <iostream>
using namespace std;

int main() {
	//the curvly braces after the variable will initial it self by its default value

	bool flag{}; //bool flag = flase ;
	int x{}; // int x = 0;

	if (flag) {
		cout << "this is not accepted" << endl;
	}

	flag = true;
	if (flag) {
		cout << "this is now acceptable" << endl;
	}

	flag = 555;
	cout << "The value of the flag is:" <<flag <<endl;

	return 0;
}