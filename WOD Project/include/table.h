/************************************************************************************************************************
*                 2023 All copyrights reserved (Vehicle Rental System project)
*      Author      : Tarun Tej Barrenkala
*      FILENAME    : table.h
*      DESCRIPTION : The objects of the Vehicle class can be stored in this file, so it is derived from Storable class.
*************************************************************************************************************************/
# ifndef table_h
# define table_h

// Include custom headers
# include "../src/storable.cpp"
# include "../src/error.cpp"

// Include standard cpp headers
# include <vector>
# include <string>
# include <fstream>
using namespace std;

/********************************************************************************************************
*       CLASS_NAME     :   Table
*       INHERITED      :   No
*       DESCRIPTION    :   This is the templated (generic) class. It represents in-memory database table.
*						   Table can be of type 'Vehicle', 'User', 'Trip'.
*       METHODS        :   Only Prototyping
*********************************************************************************************************/
template <class T> class Table 
{
	private:
		string filename;
		fstream filestream;
		
		// 'vector' is a container type and behaves like dynamic array
		vector <Storable *> *records = NULL;
		
		// Private Method Prototypes
		T *getReferenceOfRecordForId (long recordId) const throw (NoSuchRecordError);
		void writeTofile() throw (IOError);
		const T *const addNewRecord (T data) throw (MemoryError, IOError);
		void updateRecord (T updatedRecord) throw (IOError, NoSuchRecordError);
	
	public:
		// Constructor
		Table (string fileName) throw (MemoryError);
		// Destructor
		~Table();

		// Public Method Prototypes -  We will return const T *const (constant pointer to constant record). So user cannot modify that record accidentally.
		long getNextRecordId() const;
		const T *const getRecordForId (long recordId) const throw (NoSuchRecordError);

		friend class Database;
};
# endif
