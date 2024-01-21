/********************************************************************************************
*                2023 All copyrights reserved (Vehicle Rental System project) 
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : serializable.cpp
*      DESCRIPTION : Any class which is derived from this class can be converted to string
*********************************************************************************************/

// Include standard cpp headers
# include <string>
using namespace std;

/********************************************************************************************
*      CLASS_NAME     :   Serializable
*      INHERITED      :   No
*      DESCRIPTION    :   This class does not know what 'to Stirng' method will do.
*						  It is the responsibility of derived class to implement this method
*      METHODS        :   None
**********************************************************************************************/
class Serializable
{
    public :
        virtual string toString() const = 0;
};

