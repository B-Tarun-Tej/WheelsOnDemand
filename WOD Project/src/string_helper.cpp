/******************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : string_helper.cpp
*      DESCRIPTION : It comprises Helper methods related to strings
********************************************************************************/

// Include custom headers
# include "string_helper.h"

/*************************************************************************************************
*        METHOD_NAME    :   split()
*        CLASS_NAME     :   None
*        ARGUMENTS      :   2 - string &s, char delimiter
*        DESCRIPTION    :   This method splits the string at the delimiter and returns the string
*        RETURN_TYPE    :   string
**************************************************************************************************/
vector <string> split (const string &s, char delimiter)
{
	vector <string> tokens;
	string token;
	istringstream tokenStream (s);

	while (getline (tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}
