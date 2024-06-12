
#include "Container.h"
using namespace std;

namespace seneca {

	Container::Container(int m_capacity, int content) {
		this->m_capacity = m_capacity;
		m_contents = content;
	}

	ostream& Container::print(ostream& ostr)const {
		return ostr << "Capacity for the Container is: " << m_capacity << " and the Contents are: " << m_contents << endl;
	}

	Container& Container::addTo(int value) {
		m_contents += value;
		return *this;
	}

	//overloading operator +=
	Container& Container::operator+=(int value) {
		m_contents += value;
		return *this;
	}

	//getter function for the Container class to get the private member variable values
	int Container::getContent() {
		return m_contents;
	}

	//overloading operator += with non-member function
	int operator+=(int& leftOper, Container& rightOper) {

		return leftOper += rightOper.getContent();
	}

	Container::operator int()const {
		//return getContent();
		return m_contents;

	}

	Container::operator double()const {
		return m_contents/(double)m_capacity;
	}

	Container operator+(const Container& left, const Container& right) {
		return Container(left.m_contents + right.m_contents);
	}

	Container& Container::operator++() {
		if (m_contents < m_capacity) {
			m_contents++;
		}
		return *this;
	}

	Container& Container::operator++(int) {
		if (m_contents < m_capacity) {
			++m_contents;
		}
		return *this;
	}
}