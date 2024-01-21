/************************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : user.h
*      DESCRIPTION : The objects of the Vehcile class can be stored in this file, so it is derived from Storable class.
*************************************************************************************************************************/
#ifndef users_h
#define users_h

// Include custom headers
# include "../src/storable.cpp"

// Include standard cpp headers
# include <string>
using namespace std;

/********************************************************
*       CLASS_NAME     :   User
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a User
*       METHODS        :   Only Prototyping
********************************************************/
class User : public Storable
{
	private:
		string name;
		string contact;
		string email;

	public:
		// Constructor
		User (string name, string contact, string email, long recordId = 0);

		//Method Prototypes - The getter methods are marked as constant attribute because it is not changing any data of the current object
		string getName() const;
		string getContact() const;
		string getEmail() const;
		void setName (string newName);
		void setContact (string newContact);
		void setEmail (string newEmail);
		void display() const;
		string toString() const;		// Overriden Virtual Method
		void setDataFrom (Storable *s);
};
# endif

