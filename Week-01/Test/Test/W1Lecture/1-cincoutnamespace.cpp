#include <iostream>
using namespace std;

namespace myspace {

	int x = 0;

}

int x = 10;

int main() {

	cout << myspace::x << endl;
	
	cout << "Welcome to OOP244" << std::endl;
	std::cout << "Enter the value for x: " << std::endl;
	std::cin >> x;
	
	std::cout << "The value of the x is entered as : " << x << std::endl;

	return 0;
}