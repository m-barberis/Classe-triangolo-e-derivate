/// \file CIsosceles.cpp
///	\brief class Isosceles: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "CIsosceles.h"
#include <math.h>

/// @brief default constructor 
Isosceles::Isosceles() {

	cout << "Isosceles - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param s side of the Isosceles
/// @param b base of the Isosceles
Isosceles::Isosceles(float s, float b) {

	Init();

	cout << "Isosceles - constructor" << endl;

	if (s <= 0. || b <= 0.) {
		WarningMessage("constructor: side and base should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(s,b);

}

/// @brief destructor 
Isosceles::~Isosceles() {

	cout << "Isosceles - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Isosceles::Isosceles(const Isosceles &r) : Triangle(r) { 

	cout << "Isosceles - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Isosceles& Isosceles::operator=(const Isosceles &r) { 

	cout << "Isosceles - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same side and the same length  
bool Isosceles::operator==(const Isosceles &r) { 

	if (r.side == side && r.base == base)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Isosceles::Init() {
	SetDim(0,0);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Isosceles::Init(const Isosceles &r) {
	Init();
	SetDim(r.side,r.base);
}

/// @brief total reset of the object  
void Isosceles::Reset() {
	
	SetDim(0,0);
	
}


/// @brief set side of the object
/// @param w side 
void Isosceles::SetSide(float s) {

	if (s < 0.) {
		WarningMessage("Setside: side should be > 0");
		return;
	}

	SetDim(s,base);

}

/// @brief set length of the object
/// @param h base 
void Isosceles::SetBase(float b) {

	if (b < 0.) {
		WarningMessage("Setbase: base should be > 0");
		return;
	}

	SetDim(side,b);

}



/// @brief get side of the object
/// @return side 
float Isosceles::GetSide() {

	return side;

}

/// @brief get length of the object
/// @return base
float Isosceles::GetBase() {

	return base;
}

/// @brief set side and length of the object
/// @param w side 
/// @param h base
void Isosceles::SetDim(float s, float b) {

	side = s;
	base = b;  
	Triangle::SetSides(s,s,b);
	Triangle::DimControl();

	return;
}

/// @brief get side and length of the object
/// @param w side 
/// @param h base
void Isosceles::GetDim(float &s, float &b) {

	s = side;
	b = base; 
	Triangle::DimControl();
	return;
}

/// @brief computes the area of the object
/// @return the area 
float Isosceles::GetArea() {
	float halfBase = base / 2;
	return (sqrt(pow(side, 2) - pow(halfBase, 2)) * base)/2;
}


/// @brief write an error message 
/// @param string message to be printed
void Isosceles::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Isosceles --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Isosceles::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Isosceles --";
	cout << string << endl;

}

/// @brief for debugging: all about the object
void Isosceles::Dump() {
	cout << endl;
	cout << "---Isosceles---" << endl; 
	cout << endl;
	
	cout << "Side = " << side << endl;
	cout << "Base = " << base << endl;
	
	Triangle::Dump();
	
	cout << endl;

}






