#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {
    
    //check total tax
    double Bill::totalTax() const {

        double totalTAX = 0.0;

        for (int index = 0; index < m_noOfItems; index++) {

            totalTAX += m_items[index].tax();
        }

        return totalTAX;
    }

    //check total price
    double Bill::totalPrice() const {

        double totalPrice = 0.0;

        for (int index = 0; index < m_noOfItems; index++) {

            totalPrice += m_items[index].price();
        }

        return totalPrice;
    }

    //display output log header
    void Bill::Title() const {

        cout << "+--------------------------------------+" << endl;

        if (isValid()) {

            cout << "| ";

            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout.unsetf(ios::left);

            cout << " |" << endl;
        }
        else {

            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }


    //display output log footer
    void Bill::footer() const {

        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {

            cout << "|                Total Tax: ";

            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax();
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);

            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice();
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);

            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice() + totalTax();
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);

            cout << " |" << endl;
        }
        else {

            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    //set the bill to a safe empty state
    void Bill::setEmpty() {

        *m_title = '\0';
        m_items = nullptr;
    }

    //check if bill is valid
    bool Bill::isValid() const {

        bool result = true;

        if (m_title[0] != '\0' && m_items != nullptr) {

            for (int index = 0; index < m_noOfItems && result; index++) {

                if (!m_items[index].isValid()) {

                    result = false;
                }
            }
        }

        return result;
    }

    // public

    //initiate bill class
    void Bill::init(const char* title, int noOfItems) {

        if (title == nullptr || noOfItems <= 0) {

            setEmpty();
        }
        else {

            m_noOfItems = noOfItems;

            m_itemsAdded = 0;

            strncpy(m_title, title, 36);

            m_items = new Item[m_noOfItems];

            for (int position = 0; position < noOfItems; position++) {

                m_items[position].setEmpty();
            }
        }
    }

    //add item to bill
    bool Bill::add(const char* item_name, double price, bool taxed) {

        bool result = false;

        if (m_itemsAdded < m_noOfItems) {

            m_items[m_itemsAdded].set(item_name, price, taxed);

            m_itemsAdded++;
            result = true;
        }

        return result;
    }

    //display bill and each item
    void Bill::display() const {

        Title();

        for (int element = 0; element < m_noOfItems; element++) {
            m_items[element].display();
        }

        footer();
    }

    //empty memory heap
    void Bill::deallocate() {

        delete[] m_items;
        m_items = nullptr;
    }
}