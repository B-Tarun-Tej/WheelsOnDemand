# WheelsOnDemand

A VEHICLE RENTAL SYSTEM project

Wheels on Demand is an application built using C++ that helps an operator to maintain records related to users, vehicles and trips at the vehicle rental office. The functionality provided by this application includes:
1.)	Addition of new vehicles, trips and users
2.)	Editing vehicle and trip information
3.)	Viewing historical data of past trips or the trips scheduled in the future


This application is built on the concepts of Object-Oriented Programming such as Inheritance, Abstraction, Virtualization, Templates, STL, Polymorphism, I/O operations, among others.

A Database class provides abstraction layers for I/O operations. Data is brought from files to the memory and can be accessed through a Generic class Table. Table class to fetch record at a particular index. Further, exceptions have been added to handle invalid inputs.

While accessing the information, the actual data is never shared; instead, only the constant references of the data are shared. This helps to prevent accidental data corruption.

Project Structure:
my_project /
|
|-- bin/
|
|-- include/
|	|- string_helper.h
|	|- date.h
|	|- vehicle.h
|	|- user.h
|	|- trip.h
|	|- table.h
|	|- database.h
|	|- application.h
|
|-- make/
|   |-- makefile
|
|-- src/
|	|- serializable.cpp
|	|- storable.cpp
|	|- error.cpp
|	|- string_helper.cpp
|	|- date.cpp
|	|- vehicle.cpp
|	|- user.cpp
|	|- trip.cpp
|	|- table.cpp
|	|- database.cpp
|	|- application.cpp
|	|- main.cpp
|
|	|-- obj/
