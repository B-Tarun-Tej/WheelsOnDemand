/**********************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : trip.cpp
*      DESCRIPTION : The objects of the Vehicle class can be stored in this file, so it is derived from Storable class.
**********************************************************************************************************************/
// Include custom headers
# include "trip.h"
# include "../include/string_helper.h"

//Include standard cpp headers
# include <iostream>
const char DELIMITER = ';';

/**************************************************************************************
*       CLASS_NAME     :   Trip
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a User
*       METHODS        :   getUser(), getVehicle(), getStartDate(), getEndDate()
*                          getStartReading(), getEndReading(), getFare(), isCompleted() 
*						   startTrip(), completeTrip(), display(), toString(), setDataFrom()
****************************************************************************************/
// Constructor
Trip :: Trip (const Vehicle *vehicle, const User *user, Date startDate, Date endDate, long recordId, long startReading, long endReading, double fare, bool isCompleted) : Storable (recordId)
{
	this -> vehicle = vehicle;
	this -> user = user;
	this -> startDate = startDate;
	this -> endDate = endDate;
	this -> startReading = startReading;
	this -> endReading = endReading;
	this -> fare = fare;
	this -> completed = isCompleted;
}

/**************************************************************************
*        METHOD_NAME    :   getUser()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns details of the User
*        RETURN_TYPE    :   User (Here User is a class, it retruns strings)
***************************************************************************/
const User &Trip :: getUser() const
{
	return *this -> user;
}

/***********************************************************************
*        METHOD_NAME    :   getVehicle()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns details of the Vehicle
*        RETURN_TYPE    :   Vehicle (Here Vehicle is a class)
***********************************************************************/
const Vehicle &Trip :: getVehicle() const
{
	return *this -> vehicle;
}

/*************************************************************
*        METHOD_NAME    :   getStartDate()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns starting Date
*        RETURN_TYPE    :   Date (Here Date is a class)
*************************************************************/
Date Trip :: getStartDate() const
{
	return this -> startDate;
}

/***********************************************************
*        METHOD_NAME    :   getEndDate()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns ending Date
*        RETURN_TYPE    :   Date (Here Date is a class)
***********************************************************/
Date Trip :: getEndDate() const
{
	return this -> endDate;
}

/****************************************************************************
*        METHOD_NAME    :   getStartReading()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns starting point of the reading
*        RETURN_TYPE    :   long
*****************************************************************************/
long Trip :: getStartReading() const
{
	return this -> startReading;
}

/****************************************************************************
*        METHOD_NAME    :   getEndReading()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns ending point of the reading
*        RETURN_TYPE    :   long
*****************************************************************************/
long Trip :: getEndReading() const
{
	return this -> endReading;
}

/**********************************************************
*        METHOD_NAME    :   getFare()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns fare amount
*        RETURN_TYPE    :   long
***********************************************************/
long Trip :: getFare() const
{
	return this -> fare;
}

/**********************************************************************************
*        METHOD_NAME    :   isCompleted()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method defines whether the trip has completed or not
*        RETURN_TYPE    :   bool
*************************************************************************************/
bool Trip :: isCompleted() const
{
	return this -> completed;
}

/***************************************************************
*        METHOD_NAME    :   startTrip()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   1 - long startReading
*        DESCRIPTION    :   This method tracks the trip reading
*        RETURN_TYPE    :   void
***************************************************************/
void Trip :: startTrip(long startReading)
{
	this -> startReading = startReading;
}

/*****************************************************************************
*        METHOD_NAME    :   completeTrip()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   1 - long endReading
*        DESCRIPTION    :   This method returns the fare amount (trip reading)
*        RETURN_TYPE    :   double
*******************************************************************************/
double Trip :: completeTrip(long endReading)
{
	if (this -> completed)
		return this -> fare;
	
	this -> endReading = endReading;
	this -> fare = (this -> endReading - this -> startReading) * this -> vehicle -> getPricePerKm();
	this -> completed = true;

	return this -> fare;
}

/***************************************************************************
*        METHOD_NAME    :   display()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method displays all the details of the trip
*        RETURN_TYPE    :   void
****************************************************************************/
void Trip :: display() const
{
	cout << "Vehicle Details: " << endl;
	cout << "Registration No.: " << this -> vehicle -> getRegistrationNumber() << endl;
	cout << "Vehicle Type: " << this -> vehicle -> getVehicleTypeName() << endl;
	cout << "Company Name: " << this -> vehicle -> getCompanyName() << endl;
	cout << "Price per km: " << this -> vehicle -> getPricePerKm() << " Rs /km" << endl;
	cout << endl;

	cout << "User Details: " << endl;
	cout << "Name: " << this -> user -> getName() << endl;
	cout << "Contact: " << this -> user -> getContact() << endl;
	cout << endl;

	cout << "Trip Details: " << endl;
	cout << "Start Date: " << this -> startDate.toString() << endl;
	cout << "End Date: " << this -> endDate.toString() << endl;

	string tripStatus = "Not started";

	if (this -> startReading != 0)
	{
		tripStatus = "On going";
		cout << "Start reading: " << this -> startReading << endl;
	}

	if (this -> completed)
	{
		tripStatus = "Completed";
		cout << "End reading: " << this -> endReading << endl;
		cout << "Total run: " << this -> endReading - this -> startReading << endl;
		cout << "Total fare: " << this -> fare << endl;
	}

		cout << "Trip status: " << tripStatus << endl;
}

/*****************************************************************************
*        METHOD_NAME    :   toString()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method converts the data members into strings
*        RETURN_TYPE    :   string
*******************************************************************************/
string Trip :: toString() const
{
	stringstream ss;
	ss << recordId << DELIMITER
	   << vehicle -> getRecordId() << DELIMITER
	   << user -> getRecordId() << DELIMITER
	   << startDate.toString() << DELIMITER
	   << endDate.toString() << DELIMITER
	   << startReading << DELIMITER
	   << endReading << DELIMITER
	   << fare << DELIMITER
	   << completed;

	return ss.str();
}

/*****************************************************************************************************
*        METHOD_NAME    :   setDataFrom()
*        CLASS_NAME     :   Trip
*        ARGUMENTS      :   1 - Storable *s
*        DESCRIPTION    :   This method sets data to the objects, it is prototyped in Storable class
*        RETURN_TYPE    :   void
******************************************************************************************************/
void Trip :: setDataFrom (Storable *s)
{
	Trip *t = static_cast <Trip*> (s);

	if (t)
	{
		this -> vehicle = t -> vehicle;
		this -> user = t -> user;
		this -> startDate = t -> startDate;
		this -> endDate = t -> endDate;
		this -> startReading = t -> startReading;
		this -> endReading = t -> endReading;
		this -> fare = t -> fare;
		this -> completed = t -> completed;
	}
}
