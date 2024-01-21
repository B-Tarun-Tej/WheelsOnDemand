/***********************************************************************************************************************
*                2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : vehicle.h
*      DESCRIPTION : The objects of the Vehcile class can be stored in this file, so it is derived from Storable class.
***********************************************************************************************************************/

# ifndef vehicle_h
# define vehicle_h

// Include custom headers
# include "date.h"
# include "../src/storable.cpp"

// Include standard cpp headers
# include <string>
using namespace std;

// Support for different kinds of vehicles for different purposes
typedef enum
{ 
	bike = 1,
	car = 2,
	towera = 3
} VehicleType;

/**********************************************************
*       CLASS_NAME     :   Vehicle
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a Vehicle
*       METHODS        :   Only Prototyping
**********************************************************/
class Vehicle: public Storable
{
	private:
		string registrationNumber;
		VehicleType type;
		int seats;
		string companyName;
		double pricePerKm;
		Date PUCExpirationDate;

	public:
		// Constructor
		Vehicle (string registrationNumber, VehicleType type, int seats, string companyName, double pricePerKm, Date PUCExpirationDate, long recordId = 0);

		// Method Prototypes - The getter methods are marked as constant attribute because it is not changing any data of the current object
		string getRegistrationNumber() const;
		VehicleType getVehicleType() const;
		string getVehicleTypeName() const;
		int getSeats() const;
		string getCompanyName() const;
		double getPricePerKm() const;
		Date getPUCExpirationDate() const;
		void setPricePerKm (double newPrice);
		void display() const;
		string toString() const;		 // Overriden Virtual Method
		void setDataFrom (Storable *s);
};
# endif
