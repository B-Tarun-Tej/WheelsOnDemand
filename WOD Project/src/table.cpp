/*********************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : table.cpp
*      DESCRIPTION : The objects of the Vehicle class can be stored in this file, so it is derived from Storable class.
**********************************************************************************************************************/
// Include custom headers
# include "table.h"

// Include standard cpp headers
# include <iostream>
using namespace std;

/**************************************************************************************************************
*       CLASS_NAME     :   Table
*       INHERITED      :   No
*       EXCEPTIONS     :   1 (MemoryError)
*       DESCRIPTION    :   This is the templated (generic) class. It represents in-memory database table.
*                          Table can be of type 'Vehicle', 'User', 'Trip'.
*       METHODS        :   getNextRecordId(), addNewRecord(), updateRecrord(), writeTofile(), getRecordForId(),
*						   getReferenceOfRecordForId() 
***************************************************************************************************************/
// Constructor
template <class T> Table <T> :: Table (string filename) throw (MemoryError)
{
	this -> filename = filename;
	this -> records = new vector <Storable *> ();

	if (!this -> records)
		throw MemoryError();
}

/*****************************************************************
*        METHOD_NAME     :   getNextRecordId()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   None
*        DESCRIPTION     :   This method returns the Next recordId             
*        RETURN TYPE     :   long
******************************************************************/
template <class T> long Table <T> :: getNextRecordId() const
{
	return this -> records -> size() + 1;
}

/*************************************************************************************************
*        METHOD_NAME     :   addNewRecord()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   1 - T record (Here T is templated (generic) class)
*        EXCEPTIONS      :   2 (MemoryError, IOError)
*        DESCRIPTION     :   This method adds the new record to the database
*        RETURN TYPE     :   T (templated (generic) class)
**************************************************************************************************/
template <class T> const T *const Table <T> :: addNewRecord (T record) throw (MemoryError, IOError)
{
	T *newRecord = new T (record);
	
	if (!newRecord)
		throw new MemoryError();

	newRecord -> recordId = this -> getNextRecordId();
	
	// store address of new record in 'record' vector
	this -> records -> push_back (newRecord);

	// Write data to a file
	try	{
		this -> writeTofile();
	}
	catch (IOError error) {
		// Clean up things
		this -> records -> pop_back();
		delete newRecord;

		//Rethrow Exception
		throw;
	}

	return newRecord;
}

/*****************************************************************************************************
*        METHOD_NAME     :   updateRecord()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   1 - T updated Record (Here T is templated (generic) class)
*        EXCEPTIONS      :   2 (IOError, NoSuchRecorError)
*        DESCRIPTION     :   This method updates the record to the database
*        RETURN TYPE     :   void
*****************************************************************************************************/
template <class T> void Table <T> :: updateRecord(T updatedRecord) throw (IOError, NoSuchRecordError)
{
	for (auto &record : *this -> records) 
	{
		if (record -> getRecordId() == updatedRecord.getRecordId())
		{
			T *pointerToRecord = dynamic_cast <T*> (record);
			if (pointerToRecord)
			{
				T oldRecord = T (*pointerToRecord);
				record -> setDataFrom (&updatedRecord);

				// Write data to file
				try {
					this -> writeTofile();
				}
				catch (IOError error) {
					record -> setDataFrom (&oldRecord);
					
					// Rethrow Exception
					throw;
				}
			}
		}
	}
	
	throw NoSuchRecordError();
}

/****************************************************************************************************
*        METHOD_NAME     :   writeTofile()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   None
*        EXCEPTIONS      :   1 (IOError)
*        DESCRIPTION     :   This is the private method, it is called after inserting the new record
*                            or updating the data. This method writes data to a file
*        RETURN TYPE     :   void
*****************************************************************************************************/
template <class T> void Table <T> :: writeTofile() throw (IOError)
{
	/*  In this method we will overwrite file with all the data that we have. 
    	So open file with with mode 'ios::out | ios::trunc'*/

	this -> filestream.open (filename, ios::out | ios::trunc);

	if (!this -> filestream)
		throw IOError();

	for (auto &record : *records)
	{
		// Write record to file
		filestream << record -> toString() << endl;
	}

	this -> filestream.close();
}
/************************************************************************************************************
*        METHOD_NAME     :   getRecordForId()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   1 - long recordId
*        EXCEPTIONS      :   1 (NoSuchRecordError)
*        DESCRIPTION     :   This method fetches the record for particular recordId
*        RETURN TYPE     :   T (templated (generic) class)
*************************************************************************************************************/
template <class T> const T *const Table <T> :: getRecordForId (long recordId) const throw (NoSuchRecordError)
{
	try {
		return this -> getReferenceOfRecordForId (recordId);
	}
	catch (NoSuchRecordError error) {
		throw;
	}
}

/************************************************************************************************************
*        METHOD_NAME     :   getReferenceOfRecordForId()
*        CLASS_NAME      :   Table
*        ARGUMENTS       :   1 - long recordId
*        EXCEPTIONS      :   1 (NoSuchRecordError)
*        DESCRIPTION     :   This method is used to get actual record reference
*        RETURN TYPE     :   T (templated (generic) class)
*************************************************************************************************************/
template <class T> T *Table <T> :: getReferenceOfRecordForId (long recordId) const throw (NoSuchRecordError)
{
	for (auto &record : *records)
	{
		if (record -> getRecordId() == recordId)
			return dynamic_cast <T*> (record);
	}
	
	// We are out of loop hence no record is found
	throw NoSuchRecordError();
}

/******************************************
*       CLASS_NAME     :   Table
*       DESCRIPTION    :   Destructor
******************************************/
// Destructor
template <class T> Table <T> :: ~Table()
{
	// Remove any memory which is dynamically created
	for (auto &record : *this -> records)
	{
		// This is to just delete the in-memory data pointed to by 'record'
		delete dynamic_cast <T*> (record);
	}

	/* this -> records contains address of memory segments which has no data or
	   corrupted data. So clear all addresses from 'this -> records' */

	this -> records -> clear();

	// This will reduce memory size taken by vector 'this -> records'
	this -> records -> shrink_to_fit();
	
	// Finally, delete memory pointed to by vector 'this -> records'
	delete this -> records;
}
