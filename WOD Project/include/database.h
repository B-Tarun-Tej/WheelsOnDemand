/******************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : database.h
*      DESCRIPTION : This class helps in handling low-level file operations. 
*					 Database contains al Tables. This class is a friend of 
*					 Storable and Table classes
******************************************************************************/
# ifndef database_h
# define database_h

// Include custom headers
# include "vehicle.h"
# include "user.h"
# include "trip.h"
# include "../src/table.cpp"
# include "../src/error.cpp"
using namespace std;

/******************************************************************************
*       CLASS_NAME     :   Database
*       INHERITED      :   No
*       DESCRIPTION    :   This is database class. It acts as a middleware,
*						   so we can hide low-level details like file handling
*       METHODS        :   Only Prototyping
******************************************************************************/
class Database
{
	private:
		Table <Vehicle> *vehicleTable;
		Table <User> *userTable;
		Table <Trip> *tripTable;

		// Private Method Prototypes
		void fetchAllVehicles() throw (IOError, MemoryError);
		void fetchAllUsers() throw (IOError, MemoryError);
		void fetchAllTrips() throw (IOError, MemoryError);

		void cleanUp();

	public:
		// Constructor
		Database() throw (MemoryError, IOError);
		// Destructor
		~Database();

		/* Public Method Prototypes -  
		   Get references to database tables. All are constant pointers to constant objects.
		   So user can neither change pointer nor the data. */

		const Table <Vehicle> *const getVehicleRef() const;
		const Table <User> *const getUserRef() const;
		const Table <Trip> *const getTripRef() const;
		const Vehicle *const getVehicle (string registrationNo) const throw (NoSuchRecordError);
		const User *const getUser (string contactNo) const throw (NoSuchRecordError);
		const vector <const Vehicle*> getVehicle (Date startDate, Date endDate, VehicleType type) const;

		template <class T> void addNewRecord (T *record) throw (IOError, MemoryError);
		template <class T> void updateRecord (T *record) throw (IOError, NoSuchRecordError);
};
# endif
