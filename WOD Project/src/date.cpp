/***************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : date.cpp
*      DESCRIPTION : This class helps in dealing with date and time data. It is derived from Serializable class
****************************************************************************************************************/

// Include custom headers
# include "date.h"
# include "string_helper.h"

const char DELIMITER = '/';

/*******************************************************************************
*       CLASS_NAME     :   Date
*       INHERITED      :   No
*       DESCRIPTION    :   This class helps in dealing with date and time data.
*       METHODS        :   isEmpty(), toString(), operator >(), operator >=(),
* 						   operator <(), operator <=()
********************************************************************************/
// Default constructor that initializes the Date object to an empty state
Date :: Date()
{
	time_t now = time(NULL);
	this -> empty = false;
	this -> date = *localtime(&now);
}
/********************************************************************
*       CLASS_NAME     :   Date
*       INHERITED      :   No
*       DESCRIPTION    :   This class helps in dealing with date and time data.
*       METHODS        :   isEmpty(), toString(), operator >(), operator >=(),
*                          operator <(), operator <=()
**************************************************************************/
// Constructor that takes a string argument to initialize the Date object
Date :: Date(string date)
{
	// date must be in d/m/yyyy
	if (date.length() < 8)
	{
		this -> empty = true;
		return;
	}
	this -> empty = false;

	// Split the string with given delimiter
	vector <string> dateComponents = split(date, DELIMITER);

	int day = stoi (dateComponents[0]);
	int month = stoi (dateComponents[1]);
	int year = stoi (dateComponents[2]);

	time_t now = time(NULL);
	this -> date = *localtime(&now);

	this -> date.tm_year = year - 1990;
	this -> date.tm_mon = month - 1;
	this -> date.tm_mday = day;

	mktime(&this -> date);
}

/***********************************************************************************
*        METHOD_NAME    :   isEmpty()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method returns  check if the Date object is empty
*        RETURN_TYPE    :   bool
***********************************************************************************/
bool Date :: isEmpty() const
{
	return this -> empty;
}

/***********************************************************************************
*        METHOD_NAME    :   toString()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   None
*        DESCRIPTION    :   This method converts the data members into strings
*        RETURN_TYPE    :   string
***********************************************************************************/
string Date :: toString () const
{
	if (this -> empty)
		return "";

	stringstream ss;
	ss << this -> date.tm_mday << "/" << this -> date.tm_mon + 1 << "/" << this -> date.tm_year + 1990;
	return ss.str();
}

/***************************************************************************************
*        METHOD_NAME    :   operator >()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   1 - Date date (Date is structure)
*        DESCRIPTION    :   This method compare two Date objects (Overloaded > operator)
*        RETURN_TYPE    :   bool
****************************************************************************************/
bool Date :: operator > (Date date) const
{
	if (this -> isEmpty() || date.isEmpty())
		return false;

	int yearDiff = this -> date.tm_year - date.date.tm_year;
	int monthDiff = this -> date.tm_mon - date.date.tm_mon;
	int dayDiff = this -> date.tm_mday - date.date.tm_mday;

	if (yearDiff != 0)
		return yearDiff > 0;

	else if (monthDiff != 0)
		return monthDiff > 0;

	else
		return dayDiff > 0;
}

/***************************************************************************************
*        METHOD_NAME    :   operator >=()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   1 - Date date (Date is structure)
*        DESCRIPTION    :   This method compare two Date objects (Overloaded >= operator)
*        RETURN_TYPE    :   bool
****************************************************************************************/
bool Date :: operator >= (Date date) const
{
	return !(*this < date);
}

/***************************************************************************************
*        METHOD_NAME    :   operator <()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   1 - Date date (Date is structure)
*        DESCRIPTION    :   This method compare two Date objects (Overloaded < operator)
*        RETURN_TYPE    :   bool
****************************************************************************************/
bool Date :: operator < (Date date) const
{
	if (this -> isEmpty() || date.isEmpty())
		return false;

	int yearDiff = this -> date.tm_year - date.date.tm_year;
	int monthDiff = this -> date.tm_mon - date.date.tm_mon;
	int dayDiff = this -> date.tm_mday - date.date.tm_mday;

	if (yearDiff != 0)
		return yearDiff < 0;

	else if (monthDiff != 0)
		return monthDiff < 0;

	else
		return dayDiff < 0;
}

/***************************************************************************************
*        METHOD_NAME    :   operator <=()
*        CLASS_NAME     :   Date
*        ARGUMENTS      :   1 - Date date (Date is structure)
*        DESCRIPTION    :   This method compare two Date objects (Overloaded <= operator)
*        RETURN_TYPE    :   bool
****************************************************************************************/
bool Date :: operator <= (Date date) const
{
	return !(*this > date);
}
