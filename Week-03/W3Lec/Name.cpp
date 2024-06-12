#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"

using namespace std;

namespace seneca {
    int counter{};
    Name::Name() {
        m_name = m_surname = nullptr;
        cout << "Name " << ++counter << " is created" << endl;
    }

    Name::~Name() {
        deallocate();
    }

    void Name::deallocate() { //inline declaration
        cout << "Destryoing " << m_name << " and " << m_surname << endl;
        delete[] m_name;
        delete[] m_surname;
        m_name = m_surname = nullptr;
    }

    void Name::print()const {
        if (m_name && m_surname && m_name[0] && m_surname[0]) {
            cout << m_name << " " << m_surname << endl;
        }
        else {
            cout << "No name!" << endl;
        }
        //m_name = nullptr;
    }

    void Name::read() {
        char name[61];
        char surname[81];
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        set(name, surname);
    }

    void Name::set(const char* name, const char* surname) {
        deallocate();
        m_name = new char[strlen(name) + 1];
        m_surname = new char[strlen(surname) + 1];
        if (m_name && m_surname) {
            strcpy(m_name, name);
            strcpy(m_surname, surname);
        }
        else {
            deallocate();
        }
    }
}