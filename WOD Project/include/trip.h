/************************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : trip.h
*      DESCRIPTION : The objects of the Vehcile class can be stored in this file, so it is derived from Storable class.
*************************************************************************************************************************/
# ifndef trip_h
# define trip_h

// Include custom headers
# include "date.h"
# include "../src/storable.cpp"
# include "user.h"
# include "vehicle.h"

// Include standard cpp headers
# include <string>
using namespace std;

/********************************************************
*       CLASS_NAME     :   Trip
*       INHERITED      :   Yes, from Storable class
*       DESCRIPTION    :   This class represents a Trip
*       METHODS        :   Only Prototyping
********************************************************/
class Trip : public Storable
{
	private:
		const Vehicle* vehicle;
		const User* user;
		Date startDate;
		Date endDate;
		long startReading;
		long endReading;
		double fare;
		bool completed;

	public:
		// Constructor
		Trip (const Vehicle* vehicle, const User* user, Date startDate, 
			  Date endDate, long recordId = 0, long startReading = 0, 
			  long endReading = 0, double fare = 0.0, bool isCompleted = false);

		//Method Prototypes - The getter methods are marked as constant attribute because it is not changing any data of the current object
		const User &getUser() const;
		const Vehicle &getVehicle() const;
		Date getStartDate() const;
		Date getEndDate() const;
		long getStartReading() const;
		long getEndReading() const;
		long getFare() const;
		bool isCompleted() const;
		void startTrip (long startReading);
		double completeTrip (long endReading);
		void display() const;
		string toString() const;
		void setDataFrom (Storable *s);
};

# endif
