#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"
using namespace std;

namespace seneca {

	Name& Name::setName(const char* name) {
		m_data = nullptr;
		m_data = new char[strlen(name) + 1];
		strcpy(m_data, name);
		return *this;
	}

	Name& Name::setName(const char* name, int age) {
		setName(name);
		m_age = age;
		return *this;
	}

	ostream& Name::print(ostream& ostr)const {
		if (m_data)
			return ostr << m_data << " " << m_age << endl;
		else
			return ostr << "No Name has been provided" << endl;

	}

	void Name::deallocate() {
		if(m_data)
			cout << "Deleting " << m_data << " and " << m_age << endl;
		delete[] m_data;
		m_data = nullptr;
	}

	Name::~Name() {
		deallocate();
	}

	//No args constructor
	Name::Name() {
		m_data = nullptr;
		m_age = 0;
	}

	Name::Name(const char* name) {
		setName(name);
	}

	Name::Name(const char* name, int age) {
		setName(name);
		m_age = age;
	}

	Name* Name::returnValue() {
		return this;
	}

	Name& Name::returnTargetOf() {
		return *this;
	}
}
