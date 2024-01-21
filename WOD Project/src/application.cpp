/****************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : application.cpp
*      DESCRIPTION : This class handles menu and all front-end operations related to this application
*****************************************************************************************************/
// Include custom headers
# include "application.h"
# include "database_templates.cpp"

// Include standard cpp headers
# include <iostream>
# include <cstdio>
#include <limits>
#include <iomanip>
# include <cstdlib>

/******************************************************************************************************************************
*       CLASS_NAME     :   Application
*       INHERITED      :   No
*       DESCRIPTION    :   This class handles menu and all front-end operations related to this application
*       METHODS        :   gotoXY(), renderMenu(), renderAddNewVehicleMenu(), renderViewVehicleMenu(), renderEditVehicleMenu(),
*						   renderAddNewUserMenu(), renderAddNewTripMenu(),renderViewTripMenu(), renderStartTripMenu(), 
*						   showDialog(), welcome(), start(), cleanMemory()
******************************************************************************************************************************/
// Constructor
Application :: Application()
{
	try {
		this -> db = new Database();
	} 
	catch (Error e) {
		cout << e.getMessage();
		exit (EXIT_FAILURE);
	};
}

/**********************************************************************
*        METHOD_NAME     :   gotoXY()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   2 - int x, int y
*        DESCRIPTION     :  This method moves the console cursor to the 
*							specified coordinates (x, y) on the screen
*        RETURN TYPE     :   void
**********************************************************************/
void Application :: gotoXY (int x, int y) const
{
	printf ("%c[%d; %df", 0x1B, y, x);
}

/****************************************************************************************
*        METHOD_NAME     :   renderMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method displays all the available options on the screen
*        RETURN TYPE     :   void
*****************************************************************************************/
void Application :: renderMenu ()
{
	unsigned char choice = 1;
	while (true)
	{
		system ("clear");

		gotoXY (25, 4);
		cout << "Select any option from below";

		gotoXY (25, 5);
		cout << "1. Add new vehicle";

		gotoXY (25, 6);
		cout << "2. View vehicle details";

		gotoXY (25, 7);
		cout << "3. Edit vehicle details";

		gotoXY (25, 8);
		cout << "4. Add new user";

		gotoXY (25, 9);
		cout << "5. Add new trip";

		gotoXY (25, 10);
		cout << "6. View Trip";

		gotoXY (25, 11);
		cout << "7. Start Trip";

		gotoXY (25, 12);
		cout << "8. Completer Trip";

		gotoXY (25, 13);
		cout << "9. Exit";

		gotoXY (30, 15);
		printf ("Enter your choice: ");

		gotoXY (50, 15);
		cin >> choice;
		cin.ignore (numeric_limits <streamsize> :: max(), '\n');

		switch (choice)
		{
			case '1':
				this -> renderAddNewVehicleMenu();
				break;

			case '2':
				this -> renderViewVehicleMenu();
				break;

			case '3':
				this -> renderEditVehicleMenu();
				break;

			case '4':
				this -> renderAddNewUserMenu();
				break;

			case '5':
				this -> renderAddNewTripMenu();
				break;

			case '6':
				this -> renderViewTripMenu();
				break;

			case '7':
				this -> renderStartTripMenu();
				break;

			case '8':
				this -> renderCompleteTripMenu();
				break;

			case '9':
				this -> cleanMemory();
				system ("clear");
				exit (EXIT_SUCCESS);
				break;

			default:
				this -> cleanMemory();
				system ("clear");
				exit (EXIT_SUCCESS);
				break;
		}
	}
}

/********************************************************************************
*        METHOD_NAME     :   renderAddNewVehicleMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :	 This method allows to add the details of the vehicle
*        RETURN TYPE     :   void
*********************************************************************************/
void Application :: renderAddNewVehicleMenu() const
{
	string header = "Enter details of vehicle (All fields are required)";
	string registrationNoLabel = "Enter vehicle registration number: ";
	string vehicleTypeLabel = "Enter vehicle type: ";
	string vehicleOptionLabel = "(1. Bike, 2. Car, 3. Towera)";
	string seatLabel = "Enter no of seats: ";
	string companyNameLabel = "Enter name of company: ";
	string priceLabel = "Enter price per km: ";
	string pucExpirationDateLabel = "Enter PUC expiration date (d/m/yyyy): ";

	string registrationNo;
	int vehicleType;
	int seat;
	string companyName;
	double price;
	string pucExpirationDate;

	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (0, 3);
	cout << registrationNoLabel;

	gotoXY (0, 4);
	cout << vehicleTypeLabel;

	gotoXY (0, 5);
	cout << vehicleOptionLabel;

	gotoXY (0, 6);
	cout << seatLabel;

	gotoXY (0, 7);
	cout << companyNameLabel;

	gotoXY (0, 8);
	cout << priceLabel;

	gotoXY (0, 9);
	cout << pucExpirationDateLabel;

	// Prepare input fields
	gotoXY (int(registrationNoLabel.length()), 3);
	getline (cin, registrationNo);

	gotoXY (int(vehicleTypeLabel.length()), 4);
	cin >> vehicleType;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	gotoXY (int(seatLabel.length()), 6);
	cin >> seat;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	gotoXY (int(companyNameLabel.length()), 7);
	getline (cin, companyName);

	gotoXY (int(priceLabel.length()), 8);
	cin >> price;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	gotoXY (int(pucExpirationDateLabel.length()), 9);
	getline (cin, pucExpirationDate);

	Vehicle *vehicle;

	try {
		vehicle = new Vehicle (registrationNo, VehicleType(vehicleType), seat, companyName, price,  Date(pucExpirationDate));
		this -> db -> addNewRecord (vehicle);
		stringstream ss;
		ss << "Vehicle Id: " << vehicle -> getRecordId();
		showDialog ("Vehicle added successfully", ss.str());
	}
	catch (Error e) {
		showDialog (e.getMessage());
	}

	delete vehicle;
}

/******************************************************************************************
*        METHOD_NAME     :   renderViewVehicleMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method displays the information of the particular vehicle
*        RETURN TYPE     :   void
*******************************************************************************************/
void Application :: renderViewVehicleMenu() const
{
	string header = "Enter registration no. of Vehicle: ";
	string registrationNo;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (int(header.length()), 1);
	getline (cin, registrationNo);

	// Find vehicle and display data
	gotoXY (0, 3);
	try {
		auto vehicle = this -> db -> getVehicle (registrationNo);
		vehicle -> display();

		cout << endl << "Press any key to continue";
		cin.get();
	}
	catch (Error e) {
		 this -> showDialog (e.getMessage());
	}
}

/*********************************************************************
*        METHOD_NAME     :   renderEditVehicleMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method allows to modify the existing
*							 information of the particular vehicle
*        RETURN TYPE     :   void
**********************************************************************/
void Application :: renderEditVehicleMenu() const
{
	string header = "Enter registration no. of vehicle you want to edit: ";
	string priceLabel = "Enter new price per km: ";
	string registrationNo;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (int(header.length()), 1);
	getline (cin, registrationNo);

	// Find vehicle and display data
	gotoXY (0, 3);

	Vehicle *modifiedVehicle;
	try {
		auto Vehicle = this -> db -> getVehicle (registrationNo);
		Vehicle -> display();

		string newPrice;

		gotoXY (0, 12);
		cout << priceLabel;

		gotoXY (int(priceLabel.length()), 12);
		getline (cin, newPrice);

		if (newPrice != "")
		{
			modifiedVehicle -> setPricePerKm (stod(newPrice));
			this -> db -> updateRecord (modifiedVehicle);

			this -> showDialog ("Vehicle data updated successfully");
		}
	}
	catch (Error e) {
		this -> showDialog (e.getMessage());
	}

	delete modifiedVehicle;
}

/******************************************************************************
*        METHOD_NAME     :   renderAddNewUserMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method allows to adds the details of the user
*        RETURN TYPE     :   void
*******************************************************************************/
void Application :: renderAddNewUserMenu() const
{
	string header = "Enter details of user";
	string userNameLabel = "Enter name of the user: ";
	string userContactLabel = "Enter contact no of the user: ";
	string userEmailLabel = "Enter email of the user (optional): ";
	string name;
	string contact;
	string email;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (0, 3);
	cout << userNameLabel;

	gotoXY (0, 4);
	cout << userContactLabel;

	gotoXY (0, 5);
	cout << userEmailLabel;
	
	// Prepare input fields
	gotoXY (int(userNameLabel.length()), 3);
	getline (cin, name);

	gotoXY (int(userContactLabel.length()), 4);
	getline (cin, contact);

	gotoXY (int(userEmailLabel.length()), 5);
	getline (cin, email);

	User *user;
	try {
		user = new User (name, contact, email);
		this -> db -> addNewRecord (user);
		stringstream ss;
		ss << "User Id: " << user -> getRecordId();
		showDialog ("User added Successfully", ss.str());
	}
	catch (Error e) {
		showDialog (e.getMessage());
	}

	delete user;
}

/******************************************************************************
*        METHOD_NAME     :   renderAddNewTripMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method allows to add the details of the trips
*        RETURN TYPE     :   void
*******************************************************************************/
void Application :: renderAddNewTripMenu() const
{
	string header = "Enter details of the trip (All fields are required)";
	string userContactLabel = "Enter contact no of the user";
	string startDateLabel = "Enter start date of the trip (d/m/yyyy): ";
	string endDateLabel = "Enter end date of the trip (d/m/yyyy): ";
	string vehicleTypeLabel = "Enter vehicle type: ";
	string vehicleOptionLabel = "(1. Bike, 2. Car, 3. Towera)";
	string registrationNoLabel = "Enter registration no of vehicle : ";
	string contactNo;
	string startDate;
	string endDate;
	int vehicleType;
	string registrationNo;

	const User *user;
	const Vehicle *vehicle;
	system ("clear");

	gotoXY (0, 1);
	cout << userContactLabel;

	gotoXY (int(userContactLabel.length()), 1);
	getline (cin, contactNo);

	try {
		user = this -> db -> getUser(contactNo);
		gotoXY (0, 3);
		cout << "User found: " << user -> getName();
	}

	catch (Error e) {
		this -> showDialog (e.getMessage());
	}

	gotoXY (0, 5);
	cout << header;

	gotoXY (0, 7);
	cout << startDateLabel;

	gotoXY (0, 8);
	cout << endDateLabel;

	gotoXY (0, 9);
	cout << vehicleTypeLabel;

	gotoXY (0, 10);
	cout << vehicleOptionLabel;

	gotoXY (int(startDate.length()), 7);
	getline (cin, startDate);

	gotoXY (int(endDate.length()), 8);
	getline (cin, endDate);

	gotoXY (int(vehicleTypeLabel.length()), 9);
	cin >> vehicleType;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	// Find vehicle as per user's requirements, and if not found, ask the user to change the input
	auto freeVehicles = this -> db -> getVehicle(Date(startDate), Date(endDate), VehicleType(vehicleType));

	if (freeVehicles.size() == 0)
	{
		this -> showDialog ("No vehicles are free in given date range");
		return;
	}

	gotoXY (0, 12);
	cout << "|Registration no |" << "Seats |" << "Price per Km |" << endl;

	for (auto &vehicle : freeVehicles) 
	{
		string registrationNo = vehicle -> getRegistrationNumber();
		string seats = to_string (vehicle -> getSeats());

		stringstream ss;
		ss << std :: fixed;
		ss << std :: setprecision(2);
		ss << vehicle -> getPricePerKm();

		string price = ss.str() + " Rs/km";

		cout << "|" << registrationNo << string (7, ' ') << "|" << seats << string (7 - seats.length(), ' ') << "|" << price << string (14 - price.length(), ' ') << "|" << endl;
	}

	int offset = int (freeVehicles.size()) + 2;

	gotoXY (0, 12 + offset);
	cout << registrationNoLabel;

	gotoXY (int(registrationNoLabel.length()), 12 + offset);
	getline (cin, registrationNo);

	// Find vehicle with given registration number and create a trip
	try {
		vehicle = this -> db -> getVehicle (registrationNo);
	}
	catch (Error e) {
		this -> showDialog (e.getMessage());
		return;
	}

	long userId = user -> getRecordId();
	long vehicleId = vehicle -> getRecordId();

	Trip *trip;
	try {
		trip = new Trip (this -> db -> getVehicleRef() -> getRecordForId (vehicleId), this -> db -> getUserRef() -> getRecordForId (userId), Date (startDate), Date (endDate));
		this -> db -> addNewRecord (trip);
		stringstream ss;
		ss << "Trip Id: " << trip -> getRecordId();
		showDialog ("Trip added successfully", ss.str());
	}
	catch (Error e) {
		showDialog (e.getMessage());
	}

	// Release resources
	delete trip;
}

/********************************************************************************
*        METHOD_NAME     :   renderViewTripMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method displays all the information of the trip
*        RETURN TYPE     :   void
*********************************************************************************/
void Application :: renderViewTripMenu() const
{
	string header = "Enter trip id : ";
	long tripId;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (int(header.length()), 1);
	cin >> tripId;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	// FInd Trip and display data
	gotoXY (0, 3);
	try {
		auto trip = this -> db -> getTripRef() -> getRecordForId (tripId);
		trip -> display();

		cout << endl << "Press any key to continue";
		cin.get();
	}
	catch (Error e) {
		this -> showDialog (e.getMessage());
	}
}

/*****************************************************************
*        METHOD_NAME     :   renderStartTripMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method is used to start the trip
*        RETURN TYPE     :   void
******************************************************************/
void Application :: renderStartTripMenu() const
{
	string header = "Enter trip id: ";
	string readingLabel = "Enter odometer reading: ";
	long tripId;
	long startReading;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (0, 2);
	cout << readingLabel;

	gotoXY (int(header.length()), 1);
	cin >> tripId;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	gotoXY (int(readingLabel.length()), 2);
	cin >> startReading;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	Trip *modifiedTrip;
	try {
		auto trip = this -> db -> getTripRef() -> getRecordForId(tripId);
		modifiedTrip = new Trip (*trip);
		modifiedTrip -> startTrip (startReading);

		this -> db -> updateRecord (modifiedTrip);
		showDialog ("Trip started successfully");
	}
	catch (Error e) {
		this -> showDialog (e.getMessage());
	}

	delete modifiedTrip;
}

/********************************************************************
*        METHOD_NAME     :   renderCompleteTripMenu()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method is used to complete the trip
*        RETURN TYPE     :   void
*********************************************************************/
void Application :: renderCompleteTripMenu() const
{
	string header = "Enter trip id: ";
	string readingLabel = "Enter odometer reading: ";
	long tripId;
	long endReading;
	system ("clear");

	gotoXY (0, 1);
	cout << header;

	gotoXY (0, 2);
	cout << readingLabel;

	gotoXY (int(header.length()), 1);
	cin >> tripId;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	gotoXY (int(readingLabel.length()), 2);
	cin >> readingLabel;
	cin.ignore (numeric_limits <streamsize> :: max(), '\n');

	try {
		auto trip = this -> db -> getTripRef() -> getRecordForId(tripId);
		Trip *modifiedTrip = new Trip (*trip);
		auto fare = modifiedTrip -> completeTrip (endReading);
		this -> db -> updateRecord(modifiedTrip);

		stringstream ss;
		ss << "Total Fare: " << fare;
		showDialog ("Trip Completed Successfully", ss.str());
	}
	catch (Error e) {
		this -> showDialog (e.getMessage());
	}
}

/***********************************************************************************
*        METHOD_NAME     :   showDialog()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   2 - string message, string id
*        DESCRIPTION     :   This method displays the dialog box of the trip details
*        RETURN TYPE     :   void
************************************************************************************/
void Application :: showDialog (string message, string id) const
{
	auto messageLength = int (message.length());
	string pressAnyKey = "Press any key to continue";
	int infoLength = int (pressAnyKey.length());
	int leftOffset = 15;
	int length = 30;
	int lineOffset = 9;
	system ("clear");

	// Line 1
	gotoXY (leftOffset, lineOffset++);
	cout << "****************************************************************";

	// Line 2
	gotoXY (leftOffset, lineOffset);
	cout << "*";
	gotoXY (leftOffset + length - 1, lineOffset++);
	cout << "*";

	// Line 3
	gotoXY (leftOffset, lineOffset);
	cout << "*";
	gotoXY ((80 - messageLength) / 2, lineOffset);
	cout << message;
	gotoXY (leftOffset + length - 1, lineOffset++);
	cout << "*";

	if (id != "")
	{
		// Line 4
		gotoXY (leftOffset, lineOffset);
		cout << "*";
		gotoXY ((int) ((80 - int(id.length())) / 2), lineOffset);
		cout << id;
		gotoXY (leftOffset + length - 1, lineOffset++);
		cout << "*";
	}

	// Line 5
	gotoXY (leftOffset, lineOffset);
	cout << "*";
	gotoXY ((int) ((80 - infoLength) / 2), lineOffset);
	cout << pressAnyKey;
	gotoXY (leftOffset + length - 1, lineOffset++);
	cout << "*";

	// Line 6
	gotoXY (leftOffset, lineOffset);
	cout << "*";
	gotoXY (leftOffset + length - 1, lineOffset++);
	cout << "*";

	// Line 7
	gotoXY (leftOffset, lineOffset++);
	cout << "******************************************************************";
	// Wait until user press any key
	cin.get();
}

/**************************************************************************
*        METHOD_NAME     :   welcome()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method is used to display the render menu
*        RETURN TYPE     :   void
***************************************************************************/
void Application :: welcome ()
{
	system ("clear");
	gotoXY (25, 5);
	cout << "Welcome to the Vehicle Rental System" << endl;
	gotoXY (27, 23);
	cout << "Press any key to continue";

	// Wait until user press any key
	cin.get();
	this -> renderMenu();
}

/***********************************************************************************************
*        METHOD_NAME     :   start()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method is used in the main function to call the welcome method
*        RETURN TYPE     :   void
***********************************************************************************************/
void Application :: start()
{
	welcome();
}

/**************************************************************************************
*        METHOD_NAME     :   cleanMemory()
*        CLASS_NAME      :   Application
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method cleans up the memory by deleting the entire db
*        RETURN TYPE     :   void
***************************************************************************************/
void Application :: cleanMemory()
{
	delete db;
}
