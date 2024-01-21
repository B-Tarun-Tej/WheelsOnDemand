/******************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : database.cpp
*      DESCRIPTION : This class helps in handling low-level file operations. 
*					 Database contains al Tables. This class is a friend of 
*					 Storable and Table classes
******************************************************************************/
# ifndef database_cpp
# define database_cpp

// Include custom headers
# include "database.h"
# include "string_helper.h"

// Include standard cpp headers
# include <iostream>
using namespace std;

const char DELIMETER = ';';

/******************************************************************************
*       CLASS_NAME     :   Database
*       INHERITED      :   No
*       EXCEPTIONS     :   2 (IOError, MemoryError)
*       DESCRIPTION    :   This is database class. It acts as a middleware,
*                          so we can hide low-level details like file handling
*       METHODS        :   fetchAllVehicles(), fetchAllUsers(), fetchAllTrips()
*						   cleanUp(), getVehicleRef(), getUser(), getVehicle(),
*						   addNewRecord(), updateRecord()
******************************************************************************/
// Constructor
Database :: Database() throw (IOError, MemoryError)
{
	try {
		this -> vehicleTable = new Table <Vehicle> ("vehicles.txt");
		this -> userTable = new Table <User> ("users.txt");
		this -> tripTable = new Table <Trip> ("trips.txt");

		this -> fetchAllVehicles();
		this -> fetchAllUsers();
		this -> fetchAllTrips();
	}
	catch (...) {
		throw;
	}
}

/*****************************************************************
*        METHOD_NAME     :   fetchAllVehicles()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        EXCEPTIONS      :   2 (IOError, MemoryError)
*        DESCRIPTION     :   This method fetches all the vehicles
*        RETURN TYPE     :   void
******************************************************************/
void Database :: fetchAllVehicles() throw (IOError, MemoryError)
{
	this -> vehicleTable -> filestream.open (this -> vehicleTable -> filename);

	if (!this -> vehicleTable -> filestream) 
		throw IOError();
	
	// Read all lines from file
	for (string line; getline (this -> vehicleTable -> filestream, line);)
	{
		vector <string> components = split (line, DELIMETER);

		// Get all components from vector
		auto recordId = stol (components[0]);
		auto registrationNumber = components[1];
		auto type = VehicleType (stol (components[2]));
		auto seats = stoi (components[3]);
		auto companyName = components[4];
		auto pricePerKm = stod (components[5]);
		auto PUCExpirationDate = Date (components[6]);

		// Create record and store
		Storable *record = new Vehicle (registrationNumber, type, seats, companyName, pricePerKm, PUCExpirationDate, recordId);
	
		if(!recordId)
			throw MemoryError();

		this -> vehicleTable -> records -> push_back (record);
	}
	this -> vehicleTable -> filestream.close();
}

/**************************************************************
*        METHOD_NAME     :   fetchAllUsers()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        EXCEPTIONS      :   2 (IOError, MemoryError)
*        DESCRIPTION     :   This method fetches all the Users
*        RETURN TYPE     :   void
***************************************************************/
void Database :: fetchAllUsers() throw (IOError, MemoryError)
{
	this -> userTable -> filestream.open (this -> userTable -> filename);
	
	if (!this -> userTable -> filestream)
		throw IOError();
	
	// Read all lines from file
	for (string line; getline (this -> userTable -> filestream, line);)
	{
		vector <string> components = split (line, DELIMETER);
		
		// Get all components from vector
		auto recordId = stoi (components[0]);
		auto name = components[1];
		auto contact = components[2];
		auto email = components[3];

		// Create record and store
		Storable *records = new User (name, contact, email, recordId);
		
		if (!records)
			throw MemoryError();

		this -> userTable -> records -> push_back (records);
	}
	this -> userTable -> filestream.close();
}

/**************************************************************
*        METHOD_NAME     :   fetchAllTrips()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        EXCEPTIONS      :   2 (IOError, MemoryError)
*        DESCRIPTION     :   This method fetches all the Trips
*        RETURN TYPE     :   void
***************************************************************/
void Database :: fetchAllTrips() throw (IOError, MemoryError)
{
	this -> tripTable -> filestream.open (this -> tripTable -> filename);
	
	if (!this -> tripTable -> filestream)
		throw IOError();

	// Read all lines from file
	for (string line; getline (this -> tripTable -> filestream, line);)
	{
		vector <string> components = split (line, DELIMETER);

		try {
			// Get all components from vector
			auto recordId = stoi (components[0]);
			auto vehiclePtr = this -> vehicleTable -> getReferenceOfRecordForId (stoi (components[1]));
			auto userPtr = this -> userTable -> getReferenceOfRecordForId (stoi (components[2]));
			auto startDate = Date (components[3]);
			auto endDate = Date (components[4]);
			auto startReading = stol (components[5]);
			auto endReading = stol (components[6]);
			auto fare = stol (components[7]);
			auto isCompleted = components[8] == "0" ? false : true;

			// Create record and store
			Storable *record = new Trip (vehiclePtr, userPtr, startDate, endDate, recordId, startReading, endReading, fare, isCompleted);
			
			if (!record)
				throw MemoryError();
			
			this -> tripTable -> records -> push_back (record);
		}
		catch (...) {
			// just ignore this error
		}
	}
	this -> tripTable -> filestream.close();
}

/**********************************************************************************
*        METHOD_NAME     :   getVehicle()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   1 - string registrationNo
*        EXCEPTIONS      :   1 (NoSuchRecordError)
*        DESCRIPTION     :   This method fetches the vehicle by registration number
*        RETURN TYPE     :   Vehicle - Here vehicle is a class
***********************************************************************************/
const Vehicle *const Database :: getVehicle (string registrationNo) const throw (NoSuchRecordError)
{
	for (auto &record : *this -> vehicleTable -> records)
	{
		Vehicle *vehicle = dynamic_cast <Vehicle*> (record);
		if (vehicle)
		{
			if (vehicle -> getRegistrationNumber() == registrationNo)
				return vehicle;
		}
	}
	throw NoSuchRecordError();
}

/**************************************************************************
*        METHOD_NAME     :   getUser()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   1 - string contactNo
*        EXCEPTIONS      :   1 (NoSuchRecordError)
*        DESCRIPTION     :   This method fetches the user by contact number
*        RETURN TYPE     :   User - Here user is a class
***************************************************************************/
const User *const Database :: getUser (string contactNo) const throw (NoSuchRecordError)
{
	for (auto &record : *this -> userTable -> records)
	{
		User *user = dynamic_cast <User*> (record);
		if (user)
		{
			if (user -> getContact() == contactNo)
				return user;
		}
	}
	throw NoSuchRecordError();
}

/********************************************************************************
*        METHOD_NAME     :   getVehicle()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   3 - Date startDate, Date endDate, VehicleType type
*        DESCRIPTION     :   This method finds a vehicle of given type, which is
*							 available in the given duration.
*        RETURN TYPE     :   vehicles
********************************************************************************/
const vector <const Vehicle*>  Database :: getVehicle (Date startDate, Date endDate, VehicleType type) const
{
	vector <const Vehicle*> vehicles = vector <const Vehicle*> ();
	for (auto &vrecord : *this -> vehicleTable -> records)
	{
		Vehicle *vehicle = dynamic_cast <Vehicle*> (vrecord);
		if (vehicle && vehicle -> getVehicleType() == type)
		{
			// Check if this vehicle is free between startDate and endDate
			bool tripFound = false;
			for (auto & trecord : *this -> tripTable -> records)
			{
				Trip *trip = dynamic_cast <Trip*> (trecord);
				if (trip && !trip -> isCompleted() && 
					trip -> getVehicle().getRecordId() == vehicle -> getRecordId() && 
					!(trip -> getStartDate() >= endDate && trip -> getEndDate() >= endDate) &&
				    !(trip -> getStartDate() <= startDate && trip -> getEndDate () <= startDate))
				{
					tripFound = true;
					break;
				}
			}
			if (!tripFound)
				vehicles.push_back (vehicle);
		}
	}
	return vehicles;
}

/***************************************************************
*        METHOD_NAME     :   cleanUp()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method deletes all the tables
*        RETURN TYPE     :   void
***************************************************************/
void Database :: cleanUp()
{
	delete this -> vehicleTable;
	delete this -> userTable;
	delete this -> tripTable;
}

/********************************************
*        CLASS_NAME    :   Database
*       DESCRIPTION    :   Destructor
********************************************/
// Destructor
Database :: ~Database ()
{
	this -> cleanUp();
}

/*********************************************************************************
*        METHOD_NAME     :   getVehicleRef()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method gets reference to database vehicle table
*        RETURN TYPE     :   Vehicle
*********************************************************************************/
const Table <Vehicle> *const Database :: getVehicleRef() const
{
	return this -> vehicleTable;
}

/*****************************************************************************
*        METHOD_NAME     :   getUserRef()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method gets reference to database user table
*        RETURN TYPE     :   User
******************************************************************************/
const Table <User> *const Database :: getUserRef() const
{
	return this -> userTable;
}

/*****************************************************************************
*        METHOD_NAME     :   getTripRef()
*        CLASS_NAME      :   Database
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method gets reference to database trip table
*        RETURN TYPE     :   Trip
******************************************************************************/
const Table <Trip> *const Database :: getTripRef() const
{
	return this -> tripTable;
}

# endif
