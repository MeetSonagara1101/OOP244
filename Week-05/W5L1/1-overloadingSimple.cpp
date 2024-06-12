#include <iostream>

using namespace std;

/*int add(int x, int y) {
	return x + y;
}*/

double add(double x, double y) {
	return x + y;
}

int main() {

	int result = add(2, 3);
	cout << "The addition is: " << result << endl;

	double resultd = add(1.1, 2.2);
	cout << "The result of doubles is : " << resultd << endl;
	return 0;
}