/**********************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala 
*      FILENAME    : user.cpp
*      DESCRIPTION : The objects of the Vehicle class can be stored in this file, so it is derived from Storable class.
**********************************************************************************************************************/
// Include custom headers
# include "user.h"
# include "string_helper.h"

// Include standard cpp headers
# include <iostream>
const char DELIMITER = ';';

/**************************************************************************
*       CLASS_NAME     :   User
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a User
*       METHODS        :   getName(), getContact(), getEmail(),
*							setName(), setContact(), setEmail(), display()
**************************************************************************/
// Constructor
User :: User (string name, string contact, string email, long recordId) : Storable (recordId)
{
	this -> name = name;
	this -> contact = contact;
	this -> email = email;
}

/********************************************************************
*        METHOD_NAME    :   getName()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns the name of the User
*        RETURN_TYPE    :   string
*********************************************************************/
string User :: getName() const
{
	return this -> name;
}

/**********************************************************************
*        METHOD_NAME    :   getContact()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns the contact of the User
*        RETURN_TYPE    :   string
************************************************************************/
string User :: getContact() const
{
	return this -> contact;
}

/***********************************************************************
*        METHOD_NAME    :   getEmail()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns the email of the User
*        RETURN_TYPE    :   string
***********************************************************************/
string User :: getEmail() const
{
	return this -> email;
}

/***************************************************************************
*        METHOD_NAME    :   setName()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   1 - string newName
*        DESCRIPTION    :   This method updates or sets the name of the User
*        RETURN_TYPE    :   void
****************************************************************************/
void User :: setName (string newName)
{
	this -> name = newName;
}

/*******************************************************************************
*        METHOD_NAME    :   setConatct()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   1 - string newConact
*        DESCRIPTION    :   This method updates or sets the contact of the User
*        RETURN_TYPE    :   void
********************************************************************************/
void User :: setContact (string newContact)
{
	this -> contact = newContact;
}

/*******************************************************************************
*        METHOD_NAME    :   setEmail()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   1 - string newEmail
*        DESCRIPTION    :   This method updates or sets the email of the User
*        RETURN_TYPE    :   void
********************************************************************************/
void User :: setEmail (string newEmail)
{
	this -> email = newEmail;
}

/************************************************************************
*        METHOD_NAME    :   display()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method displays the details of the User
*        RETURN_TYPE    :   void
*************************************************************************/
void User :: display() const
{
	cout << "User Details: " << endl;
	cout << "Name : " << this -> name << endl;
	cout << "Contact : " << this -> contact << endl;
	cout << "Email : " << this -> email << endl;
}

/*******************************************************************************
*        METHOD_NAME    :   toString()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method converts the data members into strings
*        RETURN_TYPE    :   string
********************************************************************************/
string User :: toString () const
{
	stringstream ss;
	ss << recordId << DELIMITER
	   << name << DELIMITER
	   << contact << DELIMITER
	   << email;
 
	return ss.str();
}

/*****************************************************************************************************
*        METHOD_NAME    :   setDataFrom()
*        CLASS_NAME     :   User
*        ARGUMENTS      :   1 - Storable *s
*        DESCRIPTION    :   This method sets data to the objects, it is prototyped in Storable class
*        RETURN_TYPE    :   void
******************************************************************************************************/
void User :: setDataFrom (Storable *s)
{
	User *user = dynamic_cast <User*> (s);

	if (user)
	{
		this -> contact = user -> contact;
		this -> name = user -> name;
		this -> email = user -> email;
	}
}
