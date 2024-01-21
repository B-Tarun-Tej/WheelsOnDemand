/*******************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : error.cpp
*      DESCRIPTION : This class is used for exception handling
********************************************************************************/

// Include custom headers
# ifndef error_cpp
# define error_cpp

// Include standard cpp headers
# include <string>
using namespace std;

/***********************************************************************
*       CLASS_NAME     :   Error
*       INHERITED      :   No
*       DESCRIPTION    :   This class is used for exception handling
*       METHODS        :   getMessage()
************************************************************************/

class Error 
{
    private:
        string message;
    
    public:
		// Constructor
		Error (string message)
        {
            this -> message = message;
        }	
		
		string getMessage() const
		{
	    	return this -> message;
		}
};

/**********************************************************************************************************
*       CLASS_NAME     :   NoSuchRecordError
*       INHERITED      :   Yes, from Error class
*       DESCRIPTION    :   Error message to be thrown if the specific record is not present in the system
***********************************************************************************************************/
class NoSuchRecordError : public Error
{
    public:
		// Constructor
        NoSuchRecordError(): Error ("No such record found") {};
};

/************************************************************************************************************
*        CLASS_NAME     :   IOError
*        INHERITED      :   Yes, from Error class
*        DESCRIPTION    :   Error message to be thrown if the specific file is not present in the directory
************************************************************************************************************/
class IOError : public Error
{
    public:
		// Constructor	
        IOError(): Error ("I/O Error could not open or process file make sure 'vehicle.txt', trips.txt' and 'users.txt' file exists in this directory") {};
};

/************************************************************************************************************
*         CLASS_NAME     :   MemoryError
*         INHERITED      :   Yes, from Error class
*         DESCRIPTION    :   When systems runs out of the memory
************************************************************************************************************/
class MemoryError : public Error
{
    public:
	    // Constructor
		MemoryError(): Error ("System out of memory") {};
};
# endif
