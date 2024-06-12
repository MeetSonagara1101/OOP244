#include <iostream>
#include "MyArray.h"
using namespace std;

namespace seneca {
	MyArray::MyArray(int size) {
		cout << "constructor called" << endl;
		if (size <= 0)
			size = 1;
		m_array = new int[size];
		m_size = size;
	}

	MyArray::~MyArray() {
		cout << "destructor called" << endl;
		delete[] m_array;
	}

	int MyArray::size()const {
		return m_size;
	}

	int MyArray::element(int index) {
		return m_array[index % m_size];
	}

	int& MyArray::operator[](int index) {
		return m_array[index % m_size];
	}
}