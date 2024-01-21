/************************************************************************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : storable.cpp
*      DESCRIPTION : Any subclass of this class can be stored in a file. As all data stored in a file must be serialized, this class is derived from Serializable class.
*************************************************************************************************************************************************************************/

# ifndef storable_cpp
# define storable_cpp

// Include custom header
# include "serializable.cpp"

// Include standard cpp headers
# include <string>
# include <iostream>
using namespace std;

/******************************************************************************************************************************
*      CLASS_NAME     :   Storable
*      INHERITED      :   Yes, from Serializable class
*      DESCRIPTION    :   Anything which is storable must have 'recordId' (used as a unique key) and it must be 'Serializable'
*      METHODS        :   getRecordID()
*      RETURN TYPE    :   long Int
*******************************************************************************************************************************/
class Storable: public Serializable
{
    protected:
        // This property is protected, so only derived class can access it. Unique recordId which acts as a primary key to find data
		long recordId;
	
    public:
		// Constructor - input : recordId
		Storable (long recordId) 
		{
	    	this -> recordId = recordId;
		};
	
		long getRecordId() const
		{
	    	return this -> recordId;
		};
	
		// Method Prototype
		virtual void setDataFrom ( Storable *s) = 0;

		/* Friend Declaration 
		 * Table and Database can access private member of this class
		 * Table class: It sets 'recordId of object inside 'addNewRecord' method
		 * Database class: It sets 'recordId of object inside 'addNewRecord' method */
	
		template <class T> friend class Table;
		friend class Database;
};

# endif
