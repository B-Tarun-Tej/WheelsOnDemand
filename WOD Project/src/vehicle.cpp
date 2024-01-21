/**********************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : vehicle.cpp
*      DESCRIPTION : The objects of the Vehcile class can be stored in this file, so it is derived from Storable class.
**********************************************************************************************************************/
// Include custome headers
# include "vehicle.h"
# include "../include/string_helper.h"

const char DELIMETER = ';';

/**************************************************************************************
*       CLASS_NAME     :   Vehicle
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a Vehicle
*       METHODS        :   getRegistrationNumber(), getVehicleType(), 
*							getSeats(), getCompanyName(), getPricePerKm(), 
*							getPUCExpirationDate(), setPricePerKm(), 
*							getVehicleTypeName(), display(), toString(), setDataFrom()
***************************************************************************************/
// Constructor
Vehicle :: Vehicle (string registrationNumber, VehicleType type, int seats, string companyName, double pricePerKm, Date PUCExpirationDate, long recordId) : Storable (recordId)
{
	this -> registrationNumber = registrationNumber;
	this -> type = type;
	this -> seats = seats;
	this -> companyName = companyName;
	this -> pricePerKm = pricePerKm;
	this -> PUCExpirationDate = PUCExpirationDate;
}

/************************************************************************************
*       METHOD_NAME    :   getRegistrationNumber()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the registration number of the Vehicle
*       RETURN_TYPE    :   string
*************************************************************************************/
string Vehicle :: getRegistrationNumber () const
{
	return this -> registrationNumber;
}

/**********************************************************************
*       METHOD_NAME    :   getVehicleType()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the type of the Vehicle
*       RETURN_TYPE    :   VehicleType (Enumeration)
***********************************************************************/
VehicleType Vehicle :: getVehicleType () const
{
	return this -> type;
}

/*****************************************************************
*       METHOD_NAME    :   getSeats()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the number of seats
*       RETURN_TYPE    :   int
******************************************************************/
int Vehicle :: getSeats () const
{
	return this -> seats;
}

/*****************************************************************************
*       METHOD_NAME    :   getCompanyName()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the company name of the Vehicle
*       RETURN_TYPE    :   string
******************************************************************************/
string Vehicle :: getCompanyName() const
{
	return this -> companyName;
}

/***********************************************************************
*       METHOD_NAME    :   getPricePerKm()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the tariff per kilometer
*       RETURN_TYPE    :   double
***********************************************************************/
double Vehicle :: getPricePerKm() const
{
	return this -> pricePerKm;
}

/************************************************************************************
*       METHOD_NAME    :   getPUCExpirationDate()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the PUC Expiration Date of the vehicle
*       RETURN_TYPE    :   Date
*************************************************************************************/
Date Vehicle :: getPUCExpirationDate() const
{
	return this -> PUCExpirationDate;
}

/**********************************************************************
*       METHOD_NAME    :   setPricePerKm()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   1 - double newPrice
*       DESCRIPTION    :   This method updates new tariff per kilometer
*       RETURN_TYPE    :   void
***********************************************************************/
void Vehicle :: setPricePerKm (double newPrice)
{
	this -> pricePerKm = newPrice;
}

/***********************************************************************
*       METHOD_NAME    :   getVehicleTypeName()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method returns the type of the vehicle
*       RETURN_TYPE    :   string
***********************************************************************/
string Vehicle :: getVehicleTypeName() const
{
	switch (this -> type)
	{
		case VehicleType :: bike:
			return "Bike";
		case VehicleType :: car:
			return "Car";
		case VehicleType :: towera:
			return "Towera";
		default:
			return "";
	}
}

/*************************************************************************
*       METHOD_NAME    :   display()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method displays the details of the vehicle
*       RETURN_TYPE    :   void
***************************************************************************/
void Vehicle :: display() const
{
	cout << "Vehicle Details : " << endl;
	cout << "Registration No : " << this -> registrationNumber << endl;
	cout << "Vehicle Type : " << this -> getVehicleTypeName() << endl;
	cout << "No of seats : " << this -> seats << endl;
	cout << "Company Name : " << this -> companyName << endl;
	cout << "Price per km : " << this -> pricePerKm << " Rs/Km" << endl;
	cout << "PUC Expiration date : " << this -> PUCExpirationDate.toString() << endl;
}

/*******************************************************************************
*       METHOD_NAME    :   toString()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   None
*       DESCRIPTION    :   This method converts the data members into strings
*       RETURN_TYPE    :   string
*******************************************************************************/
string Vehicle :: toString () const
{
	stringstream ss;
	ss << recordId << DELIMETER
	   << registrationNumber << DELIMETER
	   << type << DELIMETER
	   << seats << DELIMETER
	   << companyName << DELIMETER
	   << to_string (pricePerKm) << DELIMETER
	   << PUCExpirationDate.toString();

	return ss.str();
}

/***************************************************************************************************
*       METHOD_NAME    :   setDataFrom()
*       CLASS_NAME     :   Vehicle
*       ARGUMENTS      :   1 - Storable *s
*       DESCRIPTION    :   This method sets data to the objects, it is prototyped in Storable class
*       RETURN_TYPE    :   void
****************************************************************************************************/
void Vehicle :: setDataFrom (Storable *s)
{
	Vehicle *v = dynamic_cast <Vehicle*> (s);

	if (v)
	{
		this -> registrationNumber = v -> registrationNumber;
		this -> type = v -> type;
		this -> seats = v -> seats;
		this -> companyName = v -> companyName;
		this -> pricePerKm = v -> pricePerKm;
		this -> PUCExpirationDate = v -> PUCExpirationDate;
	}
}
