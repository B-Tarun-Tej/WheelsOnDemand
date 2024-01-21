/***************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : date.h
*      DESCRIPTION : This class helps in dealing with date and time data. It is derived from Serializable class
****************************************************************************************************************/

# ifndef Date_h
# define Date_h

// Include custom headers
# include "../src/storable.cpp"

// Include standard cpp headers
# include <ctime>
# include <string>

using namespace std;

// toString() method Derived from Serializable class
typedef struct Date : Serializable
{
	// Private property - Structure holding date & time info
	private:
		struct tm date;
		bool empty;

	public:
		// Date() - This is a default constructor that initializes the Date object to an empty state.
		Date (string date);
		Date();
		Date operator + (int days);
		bool operator > (Date date) const;
		bool operator >= (Date date) const;
		bool operator < (Date date) const;
		bool operator <= (Date date) const;
		bool isEmpty() const;
		string toString () const;
} Date;
# endif
