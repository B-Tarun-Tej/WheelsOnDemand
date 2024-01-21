/****************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : application.cpp
*      DESCRIPTION : This class handles menu and all front-end operations related to this application
*****************************************************************************************************/
// Include custom headers
# include "application.h"

// Include standard cpp headers
# include <iostream>
using namespace std;

int main (int argc, const char* argv[])
{
	Application *application = new Application();
	application -> start();
}
