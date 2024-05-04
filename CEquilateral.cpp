/// \file CEquilateral.cpp
///	\brief class Equilateral: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "CEquilateral.h"
#include <math.h>

/// @brief default constructor 
Equilateral::Equilateral() {

	cout << "Equilateral - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param s side of the Equilateral
Equilateral::Equilateral(float s) {

	Init();

	cout << "Equilateral - constructor" << endl;

	if (s <= 0.) {
		WarningMessage("constructor: side and base should be > 0"); 
		SetSide(0);
	}
	else
		SetSide(s);

}

/// @brief destructor 
Equilateral::~Equilateral() {

	cout << "Equilateral - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Equilateral::Equilateral(const Equilateral &r) : Triangle(r) { 

	cout << "Equilateral - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Equilateral& Equilateral::operator=(const Equilateral &r) { 

	cout << "Equilateral - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same side   
bool Equilateral::operator==(const Equilateral &r) { 

	if (r.side == side)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Equilateral::Init() {
	SetSide(0);	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Equilateral::Init(const Equilateral &r) {
	Init();
	SetSide(r.side);
}

/// @brief total reset of the object  
void Equilateral::Reset() {
	
	SetSide(0);
	
}


/// @brief set side of the object
/// @param s side 
void Equilateral::SetSide(float s) {

	if (s < 0.) {
		WarningMessage("Setside: side should be > 0");
		return;
	}

	side = s;
	sides[0] = sides[1] = sides[2] = s;

}

/// @brief get side of the object
/// @return side 
float Equilateral::GetSide() {

	return side;

}

/// @brief computes the area of the object
/// @return the area 
float Equilateral::GetArea() {
	float halfSide = side / 2;
	return (sqrt(pow(side, 2) - pow(halfSide, 2)) * side)/2;
}


/// @brief write an error message 
/// @param string message to be printed
void Equilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Equilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Equilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Equilateral --";
	cout << string << endl;

}

/// @brief for debugging: all about the object
void Equilateral::Dump() {
	cout << endl;
	cout << "---Equilateral---" << endl; 
	cout << endl;
	
	cout << "Side = " << side << endl;
	
	Triangle::Dump();
	
	cout << endl;

}






