/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)
Full Name  : Meet Hitesh Sonagara
Student ID#: 122208226
Email      : msonagara@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Utils.h"


using namespace std;

namespace seneca {

    void flushkeys() {
        while (cin.get() != '\n');
    }

    bool ValidYesResponse(char ch) {
        return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
    }

    bool yes() {
        char ch = 0;
        do {
            cin >> ch;
            flushkeys();
        } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
        return ch == 'y' || ch == 'Y';
    }

    void readCstr(char cstr[], int len) {
        char buf[1024] = {};
        int i;
        cin.getline(buf, 1024);
        for (i = 0; i < len && buf[i]; i++) {
            cstr[i] = buf[i];
        }
        cstr[i] = 0;
    }

    int readInt(int min, int max) {
        int value = 0;
        bool done = false;
        while (!done) {
            cin >> value;
            if (!cin) {
                cin.clear();
                cout << "Bad integer, try agian: ";
            }
            else {
                if (value >= min && value <= max) {
                    done = true;
                }
                else {
                    cout << "Value out of range (" << min << "<=value<=" << max << "): ";
                }
            }
            flushkeys();
        }
        return value;
    }
}