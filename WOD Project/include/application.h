/****************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : application.h
*      DESCRIPTION : This class handles menu and all front-end operations related to this application
*****************************************************************************************************/
# ifndef application_h
# define application_h

// Include custom headers
# include "vehicle.h"
# include "user.h"
# include "trip.h"
# include "database.h"
# include "../src/error.cpp"
# include "string_helper.h"

// Include standard cpp headers
# include <fstream>
extern const char DELIMITER;

/******************************************************************************
*       CLASS_NAME     :   Application
*       INHERITED      :   No
*       DESCRIPTION    :   This class handles menu and all front-end operations 
*						   related to this application
*       METHODS        :   Only Prototyping
******************************************************************************/
class Application
{
	private:
		Database *db;

		void renderMenu();
		void welcome();
		void gotoXY (int x, int y) const;

		// Private Method Prototypes - Render Menus
		void renderAddNewVehicleMenu() const;
		void renderViewVehicleMenu() const;
		void renderEditVehicleMenu() const;
		void renderAddNewUserMenu() const;
		void renderAddNewTripMenu() const;
		void renderViewTripMenu() const;
		void renderStartTripMenu() const;
		void renderCompleteTripMenu() const;
		void showDialog (string message, string id = " ") const;

		void cleanMemory();

	public:
		// Constructor
		Application();

		// Method Prototype -  start application 
		void start();
};
# endif
