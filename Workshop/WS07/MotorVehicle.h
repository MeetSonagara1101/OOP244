#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace seneca {

    class MotorVehicle {

    private:
        char licensePlate[9];
        char address[64];
        int year;

    public:
        MotorVehicle(const char* plate, int yearBuilt);
        void moveTo(const char* address);
        ostream& write(ostream& os) const;
        istream& read(istream& in);
    };

    ostream& operator << (ostream& os, const MotorVehicle& vehicle);
    istream& operator >> (istream& in, MotorVehicle& vehicle);
}

#endif // SENECA_MOTORVEHICLE_H
