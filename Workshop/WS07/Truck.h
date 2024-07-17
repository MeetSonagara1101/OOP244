#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include "MotorVehicle.h"

using namespace std;

namespace seneca {

    class Truck : public MotorVehicle {

    private:
        double capacity;
        double currentCargo;

    public:
        Truck(const char* plate, int yearBuilt, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        ostream& write(ostream& os) const;
        istream& read(istream& in);
    };

    ostream& operator << (ostream& os, const Truck& truck);
    istream& operator >> (istream& in, Truck& truck);
}

#endif // SENECA_TRUCK_H
