#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
namespace seneca {

    void Item::setName(const char* name) {

        strncpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }

    //public functions -- BILL

    //get price and itemname to safe value
    void Item::setEmpty() {

        *m_itemName = '\0';
        m_price = 0.0;
    }

    //set item values
    void Item::set(const char* name, double price, bool taxed) {

        if ((name != nullptr) && (price > 0)) {

            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    //display item info
    void Item::display() const {

        if (isValid()) {

            cout << "| ";

            cout.width(20);
            cout.fill('.');
            cout.setf(ios::left);
            
            cout << m_itemName;
            cout.unsetf(ios::left);
            cout.fill(' ');

            cout << " | ";

            cout.width(7);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);

            if (m_taxed) {

                cout << " | Yes |" << endl;
            }
            else {

                cout << " | No  |" << endl;
            }
        }
        else {

            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    //check if item is not empty
    bool Item::isValid() const {

        bool valid = false;

        if ((*m_itemName != '\0') && (m_price > 0)) {

            valid = true;
        }

        return valid;
    }

    //check price
    double Item::price() const {

        return m_price;
    }

    //check taxed amoumt
    double Item::tax() const {

        double taxedAmount = 0.0;

        if (m_taxed) {
            taxedAmount = (m_price * 0.13);
        }

        return taxedAmount;
    }
}