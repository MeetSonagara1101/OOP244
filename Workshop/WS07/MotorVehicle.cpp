#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"

namespace seneca {
	MotorVehicle::MotorVehicle(const char* plate, int yearBuilt) : year(yearBuilt) {

		strncpy(licensePlate, plate, 8);
		licensePlate[8] = '\0'; 
		strncpy(address, "Factory", 63);
		address[63] = '\0'; 
	}

	void MotorVehicle::moveTo(const char* newAddress) {

		if (strcmp(address, newAddress) != 0) {

			cout << "|" << setw(8) << right << licensePlate;
			cout << "| |" << setw(20) << right << address;
			cout << " ---> " << setw(20) << left << newAddress << "|" << endl;

			strncpy(address, newAddress, 63);
			address[63] = '\0'; 

		}
	}

	ostream& MotorVehicle::write(ostream& os) const {

		os << "| " << year << " | " << licensePlate << " | " << address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {

		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> licensePlate;
		cout << "Current location: ";
		in.ignore();
		in.getline(address, 64);

		return in;
	}

	ostream& operator << (ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}

	istream& operator >> (istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}
}